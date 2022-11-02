#include <iostream>
using namespace std;
int b[27];
int c[37];
int sz = 0;
int main(){
    string a;
    int n;
    cin >> n >> a;
    int cur = 0;
    while(cur < a.size() && n > 0){
       if(!b[a[cur]-'a']){
           n--;
           c[sz++] = cur;
       }
       b[a[cur]-'a'] = 1;cur++;
    }
    if(n){
        cout << "NO\n";
        return 0;
    }
    c[sz++] = a.size();
    cout << "YES\n";
    for(int i = 0; i + 1 < sz; i++){
        for(int j = c[i]; j < c[i+1]; j++)
            cout << a[j];
        cout << endl;
    }
    return 0;
}