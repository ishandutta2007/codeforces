

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>


using namespace std;

typedef long long ll;



int main(){
    int t;
    
    cin >> t;
    
    while (t-- > 0) {
        long long n, a, b, c;
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;

        long long os = 0;
        long long zs = 0;
        long long cur = 0;
        vector<long long> izs;
        vector<long long> ezs;
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i - 1] == '1' && s[i] == '1') os++;
            if (i > 0 && s[i - 1] == '0' && s[i] == '0') zs++;

            if (s[i] == '1') {
                if (cur != 0) {
                    if (cur != i)
                        izs.push_back(cur-1);
                    else
                        ezs.push_back(cur);
                }
                cur = 0;
            }
            else {
                cur++;
            }

        }

        if (cur != 0) {
            ezs.push_back(cur);
        }

        sort(izs.begin(), izs.end());

        long long mxos = os;
        long long mxzs = zs;
        long long mnzs = 0;
        long long ops = 0;
        long long ans = 0;

        //cout << izs.size() << " " << ezs.size() << endl;

        for (auto p : izs) {
            long long curos = mxos;
            long long curzs = mxzs;
            if (curos > curzs + 1 + ops) curos = curzs + 1 + ops;
            if (curzs > curos + 1 - ops) curzs = curos + 1 - ops;

            if (curzs == mnzs) {
                if (curzs > curos - ops) curzs = curos - ops;
            }


            if (curzs >= mnzs) {
                ans = max(ans, a * curzs + b * curos - c * ops);
            }

            ops++;
            mnzs += p;
            mxos++;

        }

        long long curos = mxos;
        long long curzs = mxzs;
        if (curos > curzs + 1 + ops) curos = curzs + 1 + ops;
        if (curzs > curos + 1 - ops) curzs = curos + 1 - ops;
        //cout << curos << " " << curzs << " " << ops << "!" << endl;
        if (curzs == mnzs) {
            if (curzs > curos - ops) curzs = curos - ops;
        }

        if (curzs >= mnzs) {
            ans = max(ans, a * curzs + b * curos - c * ops);
            if (mxos > curos && ezs.size() >= 1) {
                ans = max(ans, a * curzs + b * curos - c * ops + b-c);
            }
            if (mxos > curos+1 && ezs.size() >= 2) {
                ans = max(ans, a * curzs + b * curos - c * ops + b + b - c - c);
            }
        }

        cout << ans << endl;

    }
}