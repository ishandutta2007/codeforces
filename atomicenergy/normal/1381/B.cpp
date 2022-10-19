#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> p;
        int mxsofar = 0;
        cin >> n;
        int cnt = 0;
        for (int i = 0; i < 2 * n; i++) {
            int x;
            cin >> x;
            if (x < mxsofar) {
                cnt++;
            }
            else {
                mxsofar = x;
                if(cnt != 0) p.push_back(cnt);
             
                cnt = 1;
            }
        }
        if(cnt > 0) p.push_back(cnt);
        bool cangetto[2005];
        for (int i = 0; i <= n; i++) {
            cangetto[i] = false;
        }
        cangetto[0] = true;
        for (int i = 0; i < p.size(); i ++) {

            for (int j = n; j >= 0; j--) {
                if (j + p[i] <= n) {
                    
                    cangetto[j + p[i]] = cangetto[j + p[i]] || cangetto[j];
                }

            }
        }
        cout << ((cangetto[n]) ? "YES" : "NO") << endl;
    }

}