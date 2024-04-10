

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>


using namespace std;



int main(){
    int t;
    
    cin >> t;
    while (t-->0) {
        long long ans = 0;
        int n;
        cin >> n;
        vector<vector<long long> > v(2 * n, vector<long long>(2 * n));
        set<pair<long long, long long> > seen;
        set < pair<long long, pair<long long, long long> > > todo;
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                cin >> v[i][j];
                if (i >= n && j >= n) {
                    ans += v[i][j];
                }
                if (i < n && j < n) {
                    todo.insert({ 0, {i, j} });
                }
            }
        }

        
        long long mn = v[0][n];
        mn = min(mn, v[n-1][n]);
        mn = min(mn, v[n][0]);
        mn = min(mn, v[n][n-1]);
        mn =  min(mn,v[0][2*n-1]);
        mn = min(mn, v[n - 1][2*n-1]);
        mn = min(mn, v[2*n-1][0]);
        mn = min(mn, v[2*n-1][n - 1]);

        cout << ans+mn << endl;
    }


}