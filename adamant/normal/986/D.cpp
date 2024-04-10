#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

#define int int64_t
const int logn = 22;
const int maxn = 1 << logn;

typedef complex<double> ftype;
const double pi = acos(-1);
ftype w[maxn];

template<typename T>
void fft(T *in, T *out, int n, int k) {
    if(n == 1) {
        *out = *in;
        return;
    }
    n /= 2;
    fft(in, out, n, 2 * k);
    fft(in + k, out + n, n, 2 * k);
    for(int i = 0; i < n; i++) {
        ftype t = w[i + n] * out[i + n];
        out[i + n] = out[i] - t;
        out[i] = out[i] + t;
    }
}

const int mod = 1e4, len = 4;

void normalize(vector<int> &ans) {
    int carry = 0;
    for(int i = 0; i < (int)ans.size(); i++) {
        ans[i] += carry;
        carry = ans[i] / mod;
        ans[i] -= carry * mod;
    }
    if(carry) {
        ans.push_back(carry);
    }
    while(ans.back() == 0 && ans.size() > 1) {
        ans.pop_back();
    }
}

ftype sqr(ftype x) {
    return x * x;
}

vector<int> mul(vector<int> a, vector<int> b) {
    int n = a.size() + b.size();
    while(__builtin_popcount(n) != 1)
        n++;
    while((int)a.size() < n)
        a.push_back(0);
    while((int)b.size() < n)
        b.push_back(0);

    vector<ftype> A(n);
    for(int i = 0; i < n; i++) {
        A[i] = ftype(a[i], b[i]);
    }
    vector<ftype> nA(n);
    fft(A.data(), nA.data(), n, 1);
    for(int i = 0; i < n; i++) {
        A[i] = (sqr(nA[i]) - sqr(conj(nA[(n - i) % n]))) / ftype(0, 4);
    }
    fft(A.data(), nA.data(), n, 1);
    reverse(begin(nA) + 1, end(nA));
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        ans[i] = llround(real(nA[i]) / n);
    }
    normalize(ans);
    return ans;
}

vector<int> ppow(vector<int> x, int n) {
    if(n == 0) {
        return {1};
    } else if(n == 1 && false) {
        return x;
    } else {
        auto t = ppow(x, n / 2);
        t = mul(t, t);
        return n % 2 ? mul(t, x) : t;
    }
}

const int loggn = 22;
vector<int> pows[loggn];

string to_string(vector<int> x) {
    stringstream ss;
    reverse(begin(x), end(x));
    ss << x[0];
    for(int i = 1; i < (int)x.size(); i++) {
        ss << setfill('0') << setw(len) << x[i];
    }
    return ss.str();
}

void print(vector<int> x) {
    cout << to_string(x) << endl;
}

bool les(const string &a, const string &b) {
    if(a.size() != b.size()) {
        return a.size() < b.size();
    } else {
        return a < b;
    }
}

vector<int> mul(vector<int> a, int c) {
    for(auto &it: a) {
        it *= c;
    }
    normalize(a);
    return a;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); //
    for(int z = 1; z < maxn; z *= 2) {
        for(int i = 0; i < z; i++) {
            w[z + i] = polar(1., pi * i / z);
            assert(z + i < maxn);
        }
    }
    //return 0;
    pows[0] = {3};
    for(int i = 1; i < loggn; i++) {
        pows[i] = mul(pows[i - 1], pows[i - 1]);
    }
    string control;
    cin >> control;
    //control = string(1500000, '9');
    if(control == "1") {
        cout << 1 << endl;
        return 0;
    } else if(control == "2") {
        cout << 2 << endl;
        return 0;
    }
    int ans = 1e9;
    int k = max<int>(0, (int)round(control.size() * log(10) / log(3)) - 3);
    vector<int> cur = ppow({3}, k);
    while(!les(control, to_string(mul(cur, 9)))) {
        cur = mul(cur, 3);
        k++;
    }
    if(!les(to_string(mul(cur, 3)), control)) {
        ans = min(ans, 3 * k + 3);
    }
    if(!les(to_string(mul(cur, 2 * 2)), control)) {
        ans = min(ans, 3 * k + 2 + 2);
    }
    if(!les(to_string(mul(cur, 3 * 2)), control)) {
        ans = min(ans, 3 * k + 3 + 2);
    }
    if(!les(to_string(mul(cur, 3 * 3)), control)) {
        ans = min(ans, 3 * k + 3 + 3);
    }
    cout << ans << endl;
    return 0;
}