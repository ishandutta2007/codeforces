#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    cin >> N;
    N--;
    cout << "1 0" << endl;
    string s;
    cin >> s;
    bool lft = (s == "white");
    pair<pair<int, int>, pair<int, int>> ans = {{2, 0}, {2, 1}};
    int l = 1, r = 999999999;
    while(N--){
        int mid = l+r>>1;
        cout << "1 " << mid << endl;
        cin >> s;
        if(s == "black"){
            if(!lft){
                l = mid+1;
            }
            else{
                ans = {{1000, mid}, {0, mid-1}};
                r = mid-1;
            }
        }
        else{
            if(lft){
                l = mid+1;
            }
            else{
                ans = {{1000, mid}, {0, mid-1}};
                r = mid-1;
            }
        }
    }
    cout << ans.first.first << " " << ans.first.second << " " << ans.second.first << " " << ans.second.second << endl;
}