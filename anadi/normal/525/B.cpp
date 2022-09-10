#include <iostream>
#include <string>

using namespace std;

bool t[100005];

char result[200005];

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int x=s.size();
    int q;
    cin >> q;
    while(q--){
        int m;
        cin >> m;
        t[m-1]^=1;
    }
    int which=0;
    for(int i=0;i<(x+1)/2;++i){
        which+=t[i];
        if(which%2==0){
            result[i]=s[i];
            result[x-i-1]=s[x-i-1];
        }
        else{
            result[i]=s[x-i-1];
            result[x-i-1]=s[i];
        }
    }
    for(int i=0;i<x;++i)
        cout << result[i];
    return 0;
}