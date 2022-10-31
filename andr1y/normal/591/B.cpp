#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    string str,res;
    cin >> str;
    char alpha[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char x1,x2;
    for(int i = 0 ; i < m; i++){
        cin >> x1 >> x2;
        if(x1!=x2){
            for(int j = 0 ; j < 27 ; j++){
                if(alpha[j]==x1)alpha[j]=x2;
                else if(alpha[j]==x2)alpha[j]=x1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        str[i] = alpha[str[i]-'a'];
    }
    cout << str;
}