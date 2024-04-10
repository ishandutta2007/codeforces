#include <bits/stdc++.h>

using namespace std;

int N;
stack<long long> stk;
int notoverflow = 1;
long long tot = 0;

int main(){
    cin >> N;
    stk.push(1);
    while(N--){
        string s;
        cin >> s;
        if(s == "for"){
            long long n;
            cin >> n;
            stk.push(n*stk.top());
            if(stk.top() <= (1LL<<32)-1 && notoverflow == stk.size()-1){
                notoverflow++;
            }
        }
        else if(s == "add"){
            if(stk.size() > notoverflow){
                cout << "OVERFLOW!!!" << endl;
                return 0;
            }
            tot += stk.top();
            if(tot > (1LL<<32)-1){
                cout << "OVERFLOW!!!" << endl;
                return 0;
            }
        }
        else{
            stk.pop();
            if(stk.size() < notoverflow){
                notoverflow--;
            }
        }
    }
    cout << tot << endl;
}