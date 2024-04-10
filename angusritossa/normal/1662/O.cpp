#include <bits/stdc++.h>

#define M_PIL 3.141592653589793238462643383279502884L

#define ld long double
#define ll long long

using namespace std;

struct circle {
    int radius;
    bitset<720> is_open;
    bitset<720> has_wall;
};
bool operator< (const circle& a, const circle& b) {
    return a.radius < b.radius;
}

struct wall {
    int enddists[2];
    int angle;
};
bool operator< (const wall& a, const wall& b) {
    if (a.angle != b.angle) {
        return a.angle < b.angle;
    }
    return a.enddists[0] < b.enddists[0];
}

bitset<720> seen[21];
vector<circle> circles;

bool dfs(int c, int angle) {
    if (c < 0 || seen[c][angle]) {
        return false;
    }
    if (c >= circles.size() || circles[c].radius > 20) {
        return true;
    }
    seen[c][angle] = true;
    if (circles[c].is_open[angle]) {
        if (dfs(c+1, angle)) {
            return true;
        }
    }
    if (c > 0) {
        if (circles[c-1].is_open[angle]) {
            if (dfs(c-1, angle)) {
                return true;
            }
        }
    }
    if (!circles[c].has_wall.test((angle+1)%720)) {
        if (dfs(c,(angle+1)%720)) {
            return true;
        }
    }
    if (!circles[c].has_wall.test((angle-1+720)%720)) {
        if (dfs(c,(angle-1+720)%720)) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    scanf("%d",&n);
    circles.clear();
    vector<wall> walls;
    for (int i=0;i<20;i++) {
        seen[i].reset();
    }
    for (int i=0;i<n;i++) {
        char st[2];
        scanf("%s", st);
        if (st[0] == 'C') {
            circle tem;
            int angles[2];
            scanf("%d %d %d", &tem.radius, &angles[0], &angles[1]);
            tem.is_open.set();
            tem.has_wall.reset();
            if (angles[1] < angles[0]) {angles[1] += 360;}
            angles[0] *= 2;
            angles[1] *= 2;
            for (int i=angles[0]; i <= angles[1]; i++) {
                tem.is_open.reset(i%720);
            }
            circles.push_back(tem);
        }
        else {
            wall tem;
            scanf("%d %d %d",&tem.enddists[0], &tem.enddists[1], &tem.angle);
            tem.angle *= 2;
            walls.push_back(tem);
        }
    }

    sort(circles.begin(), circles.end());
    for (int i=1;i<circles.size();i++) {
        if (circles[i].radius == circles[i-1].radius) {
            circles[i-1].radius = 21;
            for (int j=0;j<720;j++) {
                if (!circles[i-1].is_open.test(j)) {
                    circles[i].is_open.reset(j);
                }
            }
        }
    }
    sort(circles.begin(), circles.end());

    sort(walls.begin(), walls.end());
    for (int i=1;i<walls.size();i++) {
        if (walls[i].angle == walls[i-1].angle) {
            if (walls[i].enddists[0] == walls[i-1].enddists[1]) {
                walls[i-1].enddists[0] = 21;
                walls[i].enddists[0] = walls[i-1].enddists[0];
            }
        }
    }
    sort(walls.begin(), walls.end());

    for (int i=1;i<circles.size() && circles[i].radius <= 20; i++) {
        for (int j=0;j<walls.size() && walls[j].enddists[0] <= 20;j++) {
            if (walls[j].enddists[0] <= circles[i-1].radius && walls[j].enddists[1] >= circles[i].radius) {
                circles[i].has_wall.set(walls[j].angle);
                circles[i-1].is_open.reset(walls[j].angle);
            }
        }
    }

    if (dfs(0,0)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int t;
    scanf("%d",&t);
    for (int i=0;i<t;i++) {
        solve();
    }
}