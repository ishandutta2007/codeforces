using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;

int a[1500][1502];
int b[1500][1502];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            a[i][1501] +=  j * a[i][j];
            a[i][1501] %= 12345;
        }
        a[i][m] = i;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> b[i][j];
            b[i][1501] +=  j * b[i][j];
            b[i][1501] %= 12345;
        }
        b[i][m] = -1;
    }
    for(int i=0; i<n; i++){
        bool matched = false;
        for(int j=0; j<n; j++){
            if(a[i][1501] != b[j][1501]) continue;
            if(b[j][m] != -1) continue;
            bool match = true;
            for(int k=0; k<m; k++){
                if(a[i][k] != b[j][k]) {
                    match = false;
                }
            }
            if(match && b[j][m] == -1){
                b[j][m] = i;
                j = n+1;
                matched = true;
            }
        }
        if(!matched){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<int> notdone;
    vector<int> worry;
    vector<int> waiting(m, 0);
    for(int i=0; i<m; i++){
        notdone.push_back(i);
    }
    for(int i=0; i<n-1; i++){
        worry.push_back(i);
    }
    vector<int> ans;
    for(int i=0; i<m; i++){
        for(int j : worry){
            if(!(b[j][i] <= b[j+1][i])) waiting[i]++;
        }
    }

    while(true){
        bool didsomething = false;

        for(int ii=0; ii<notdone.size(); ii++){

            int i = notdone[ii];
            bool ok = true;
           

            if(waiting[i] == 0){
                
                ans.push_back(i+1);
                for(int jj=0; jj<worry.size(); jj++){
                    int j = worry[jj];
                    if(b[j][i] < b[j+1][i]) {
                        worry.erase(worry.begin() + jj);
                        for(int iii=0; iii<m; iii++){
                            if(!(b[j][iii] <= b[j+1][iii])) waiting[iii]--;
                        }
                        jj--;
                        didsomething = true;
                    }
                }
                notdone.erase(notdone.begin() + ii);
                ii--;
            }
        }
        if(!didsomething){
            break;
        }
    }
    for(int j : worry){
        if(b[j][m] > b[j+1][m]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans.size() << endl;
    for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i] << " ";
    }
}