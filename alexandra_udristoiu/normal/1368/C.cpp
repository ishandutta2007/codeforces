#include<iostream>
using namespace std;
int n, i, nr;
pair<int, int> v[500005], p;
int main(){
    cin>> n;
    v[++nr] = make_pair(0, 0);
    v[++nr] = make_pair(0, 1);
    v[++nr] = make_pair(1, 0);
    v[++nr] = make_pair(1, 1);
    for(i = 1; i <= n; i++){
        p = v[nr];
        v[++nr] = make_pair(p.first + 1, p.second);
        v[++nr] = make_pair(p.first, p.second + 1);
        v[++nr] = make_pair(p.first + 1, p.second + 1);
    }
    cout<< nr <<"\n";
    for(i = 1; i <= nr; i++){
        cout<< v[i].first <<" "<< v[i].second <<"\n";
    }
}