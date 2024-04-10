#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

using my_float = long double;

struct point {
    my_float x, y;

    point() : x(0), y(0) {}

    point(my_float _x, my_float _y) : x(_x), y(_y) {}

    point& operator+=(const point &other) { x += other.x; y += other.y; return *this; }
    point& operator-=(const point &other) { x -= other.x; y -= other.y; return *this; }
    point& operator*=(my_float mult) { x *= mult; y *= mult; return *this; }

    point operator+(const point &other) const { return point(*this) += other; }
    point operator-(const point &other) const { return point(*this) -= other; }
    point operator*(my_float mult) const { return point(*this) *= mult; }

    // Warning: does exact floating-point comparisons.
    bool operator==(const point &other) const { return x == other.x && y == other.y; }
    bool operator!=(const point &other) const { return !(*this == other); }

    point operator-() const { return point(-x, -y); }
    point rotate90() const { return point(-y, x); }

    my_float norm() const {
        return x * x + y * y;
    }

    my_float dist() const {
        return sqrt(norm());
    }

    bool top_half() const {
        return make_pair(y, x) > pair<my_float, my_float>(0, 0);
    }

    friend ostream& operator<<(ostream &os, const point &p) {
        return os << '(' << p.x << ", " << p.y << ')';
    }
};

my_float cross(const point &a, const point &b) {
    return a.x * b.y - b.x * a.y;
}

my_float dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

bool left_turn_strict(const point &a, const point &b, const point &c) {
    return cross(b - a, c - a) > 0;
}

bool left_turn_lenient(const point &a, const point &b, const point &c) {
    return cross(b - a, c - a) >= 0;
}

// Warning: does a floating-point comparison to exactly 0.
bool collinear(const point &a, const point &b, const point &c) {
    return cross(b - a, c - a) == 0;
}

// Returns twice the signed area formed by three points in a triangle. Positive when a -> b -> c is a left turn.
my_float area_signed_2x(const point &a, const point &b, const point &c) {
    return cross(b - a, c - a);
}

my_float distance_to_line(const point &p, const point &a, const point &b) {
    assert(a != b);
    return abs(area_signed_2x(p, a, b)) / (a - b).dist();
}

my_float manhattan_dist(const point &a, const point &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

my_float infinity_norm_dist(const point &a, const point &b) {
    return max(abs(a.x - b.x), abs(a.y - b.y));
}

// Sort in increasing order of y, with ties broken in increasing order of x.
bool yx_compare(const point &a, const point &b) {
    return (b - a).top_half();
}

// Sort in increasing order of angle to the x-axis.
bool angle_compare(const point &a, const point &b) {
    if (a.top_half() ^ b.top_half())
        return a.top_half();

    return cross(a, b) > 0;
}


const my_float SEARCH_MAX = 10e9;
const my_float EPS = 1e-12;
const int SEARCH_ITERS = 25;

int N;
vector<point> cars, direction;
vector<my_float> speed;

struct segment {
    point p, q;

    void reorder() {
        if (p.x > q.x)
            swap(p, q);
    }

    my_float eval_y(my_float x) const {
        my_float fraction = (x - p.x) / (q.x - p.x);
        return p.y + fraction * (q.y - p.y);
    }
};

vector<segment> segs;
my_float current_x;

bool has_intersection(my_float time) {
    segs.resize(N);

    for (int i = 0; i < N; i++) {
        segs[i].p = cars[i];
        segs[i].q = cars[i] + direction[i] * speed[i] * time;
        segs[i].reorder();
    }

    vector<pair<my_float, int>> events;

    for (int i = 0; i < N; i++) {
        events.emplace_back(segs[i].p.x, i + 1);
        events.emplace_back(segs[i].q.x, -(i + 1));
    }

    sort(events.begin(), events.end());
    current_x = events.front().first;

    struct compare_seg {
        bool operator()(int a, int b) const {
            if (a == b)
                return false;

            return segs[a].eval_y(current_x) < segs[b].eval_y(current_x);
        }
    };

    set<int, compare_seg> ordered_segs;

    for (auto &e : events) {
        current_x = e.first;
        int index = abs(e.second) - 1;
        bool add = e.second > 0;
        set<int, compare_seg>::iterator it;

        if (add)
            it = ordered_segs.insert(index).first;
        else
            it = ordered_segs.find(index);

        if (it == ordered_segs.end() || *it != index)
            return true;

        if (it != ordered_segs.begin()) {
            auto before = it;
            before--;

            if (segs[index].eval_y(current_x) - segs[*before].eval_y(current_x) < EPS)
                return true;
        }

        auto after = it;
        after++;

        if (after != ordered_segs.end()) {
            if (segs[*after].eval_y(current_x) - segs[index].eval_y(current_x) < EPS)
                return true;
        }

        if (!add)
            ordered_segs.erase(it);
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cout << setprecision(16);

    cin >> N;
    cars.resize(N);
    direction.resize(N);
    speed.resize(N);

    for (int i = 0; i < N; i++) {
        int x, y, dx, dy, s;
        cin >> x >> y >> dx >> dy >> s;
        cars[i] = point(x, y);
        direction[i] = point(dx, dy);
        direction[i] *= 1 / direction[i].dist();
        speed[i] = s;
    }

    my_float low = 0, high = SEARCH_MAX;

    if (!has_intersection(high)) {
        cout << "No show :(" << '\n';
        return 0;
    }

    if (has_intersection(1))
        high = 1;
    else
        low = 1;

    for (int iter = 0; iter < SEARCH_ITERS; iter++) {
        my_float mid = high <= 1 ? (low + high) / 2 : sqrt(low * high);

        if (has_intersection(mid))
            high = mid;
        else
            low = mid;
    }

    cout << low << '\n';
}