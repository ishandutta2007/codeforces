#include<bits/stdc++.h>
//#include<atcoder/dsu>
using namespace std;
//using namespace atcoder;

void solve(){
	int n;
    string S;
    cin >> n >> S;
    int t = 0;
    for(auto s:S){
        if(s < '1'){
            break;
        }
        else if(s > '1'){
            t = 2;
            break;
        }
    }
    // 222...222 
    if(t == 0){
        bool car = false;
        string T;
        for(int i = n - 1; i >= 0; i--){
            int s = S[i] - '0';
            int x = 2;
            if(car) x--;
            if(x >= s){
                T += char('0' + x - s);
                car = false;
            }
            else{
                T += char('0' + 10 + x - s);
                car = true;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            cout << T[i];
        }
        cout << "\n";
    }
    // 111...1111
    else{
        bool car = false;
        string T;
        for(int i = n - 1; i >= 0; i--){
            int s = S[i] - '0';
            int x = 1;
            if(car) x--;
            if(x >= s){
                T += char('0' + x - s);
                car = false;
            }
            else{
                T += char('0' + 10 + x - s);
                car = true;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            cout << T[i];
        }
        cout << "\n";
    }

}

int main(){	
	cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}