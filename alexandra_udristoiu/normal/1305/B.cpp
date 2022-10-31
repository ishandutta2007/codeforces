#include<iostream>
#include<cstring>
using namespace std;
int n, i, p;
char s[1005];
int num[1005], num2[1005];
int main(){
    cin>> s + 1;
    n = strlen(s + 1);
    p = 1;
    while(s[p] == ')'){
        p++;
    }
    while(s[p] == '('){
        p++;
    }
    if(p == n + 1){
        cout<< 0;
        return 0;
    }
    for(i = 1; i <= n; i++){
        num[i] = num[i - 1];
        if(s[i] == '('){
            num[i]++;
        }
    }
    for(i = n; i >= 1; i--){
        num2[i] = num2[i + 1];
        if(s[i] == ')'){
            num2[i]++;
        }
    }
    for(i = 1; i <= n; i++){
        if(num[i] == num2[i + 1]){
            p = i;
            break;
        }
    }
    cout<<"1\n"<< num[p] * 2 <<"\n";
    for(i = 1; i <= n; i++){
        if(i <= p && s[i] == '('){
            cout<< i <<" ";
        }
        if(i > p && s[i] == ')'){
            cout<< i <<" ";
        }
    }
}