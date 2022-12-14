#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

bool solve(string &s, int a, int b, int c, int d) {
    int diff = 0;
    for(char c : s) {
        diff += c == 'A' ? 1 : -1;
    }
    if(diff != a-b)
        return false;
    vector<int> both, sa, sb;
    {
        char last = 0;
        char start = 0;
        int cnt = 0;
        for(char c: s) {
            if(last == 0) {
                start = c;
                cnt = 1;
            } else if(last == c) {
                if(start == last)            
                    both.push_back((cnt-1) / 2);
                else if(start == 'A')
                    sa.push_back(cnt/2);
                else if(start == 'B')
                    sb.push_back(cnt/2);
                start = c;
                cnt = 1;
            } else {
                cnt++;
            } 
            last = c;
        }
        // cout << "HET " << start << " " << last << " " << cnt << endl;
        if(start == last)            
            both.push_back((cnt-1) / 2);
        else if(start == 'A')
            sa.push_back(cnt/2);
        else if(start == 'B')
            sb.push_back(cnt/2);
    }
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    for(int x : sa) {
        if(c >= x) {
            c -= x;
        } else if(x > 0) {
            d -= (x-1-c);
            d = max(d, int(0));
            c = 0;
        }
    }
    for(int x : sb) {
        if(d >= x) {
            d -= x;
        } else if(x > 0) {
            c -= (x-1-d);
            c = max(c, int(0));
            d = 0;
        }
    }
    // cout << c << " " << d << endl;
    int sm = 0;
    for(int x : both) {
        sm += x;
    }

    return c + d <= sm;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int a, b, c, d;
        string s;
        cin >> a >> b >> c >> d;
        cin >> s;
        cout << (solve(s, a, b, c, d) ? "YES\n" : "NO\n");
    }
    return 0;
}