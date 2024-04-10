#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//set <string> names;
int cnt,ans;
string s;

int main(){
    while(getline(cin, s)){
        if (s[0]=='+'){
            cnt++;
        }
        else if (s[0]=='-'){
            cnt--;
        }
        else{
            int f=0, k=s.size();
            for (int i=0; i<k; i++){
                if (s[i]==':'){
                    f=i;
                    break;
                }
            }
            ans+=(k-f-1)*cnt;
        }
    }
    cout<<ans<<endl;
    return 0;
}