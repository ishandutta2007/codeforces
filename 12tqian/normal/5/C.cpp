#include <bits/stdc++.h>
using namespace std;
static int len[1000005];
int main(){
    string s;
    cin >> s;
    stack<int> stk;
    stk.push(-1);
    int res = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '('){
            stk.push(i);
        }
        else{
            stk.pop();
            if(!stk.empty()){

                if(i-stk.top()>=res){
                    res = max(res, i-stk.top());
                    len[res] += 1;
                }

            }
            else{
                stk.push(i);
            }
        }
    }
    if(res == 0){
        cout << 0 << " " << 1<<endl;
        return 0;
    }
    cout<< res<< " " << len[res]<< endl;
    return 0;
}