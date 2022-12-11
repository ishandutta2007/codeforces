#include <bits/stdc++.h>

using namespace std;

string s;

int query(int l, int r){
    cout << "? " << l << " " << r << endl;
    cin >> s;
    return (s == "x");
}

int main(){
    while(true){
        cin >> s;
        if(s == "start"){
            int ans = 1;
            bool done = 0;
            for(int i = 1, crnt = 1; !done && i<=30; i++){
                if(query(crnt, min(1000000000, crnt+(1<<i)))){
                    ans = min(crnt+(1<<i), 1000000000);
                    int l = crnt+1, r = crnt+(1<<i);
                    while(l <= r){
                        int mid = l+r>>1;
                        if(query(crnt, mid)){
                            ans = mid;
                            r = mid-1;
                        }
                        else{
                            l = mid + 1;
                        }
                    }
                    if(ans == 2){
                        if(query(2, 3)){
                            ans = 1;
                        }
                    }
                    cout << "! " << ans << endl;
                    done = 1;
                }
                else{
                    crnt += (1<<i);
                }
            }
        }
        else{
            break;
        }
    }
}