#include<iostream>
#include<vector>
#define DIM 100005
using namespace std;
int t, n, i, nr, j;
char s[DIM];
int v[DIM], r[DIM], viz[DIM], val[DIM];
vector<int> sol[4], w;
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        //i i - 1
        if(n / 2 > 0){
            cout<<"Q "<< n / 2 <<" ";
            for(i = 1; i < n; i += 2){
                cout<< i <<" "<< i + 1 <<" ";
            }
            cout<<"\n";
            cout.flush();
            cin>> s + 1;
        }
        for(i = 2; i <= n; i += 2){
            r[i] = s[i / 2] - '0';
        }
        if( (n - 1) / 2 > 0){
            cout<<"Q "<< (n - 1) / 2 <<" ";
            for(i = 2; i < n; i += 2){
                cout<< i <<" "<< i + 1 <<" ";
            }
            cout<<"\n";
            cout.flush();
            cin>> s + 1;
        }
        for(i = 3; i <= n; i += 2){
            r[i] = s[i / 2] - '0';
        }
        //i i - 2
        nr = v[1] = 1;
        for(i = 2; i <= n; i++){
            if(r[i] == 0){
                v[++nr] = i;
            }
        }
        v[nr + 1] = n + 1;
        for(i = 1; i <= nr; i++){
            viz[i] = val[i] = 0;
        }
        for(i = 3; i <= nr; i++){
            if(viz[i - 2] == 0){
                w.push_back(i);
                viz[i] = 1;
            }
        }
        if(w.size() != 0){
            cout<<"Q "<< w.size() <<" ";
            for(i = 0; i < w.size(); i++){
                cout<< v[ w[i] - 2 ] <<" "<< v[ w[i] ] <<" ";
            }
            cout<<"\n";
            cout.flush();
            cin>> s + 1;
        }
        for(i = 0; i < w.size(); i++){
            r[ w[i] ] = s[i + 1] - '0';
        }
        w.clear();
        for(i = 3; i <= nr; i++){
            if(viz[i] == 0){
                w.push_back(i);
                viz[i] = 1;
            }
        }
        if(w.size() != 0){
            cout<<"Q "<< w.size() <<" ";
            for(i = 0; i < w.size(); i++){
                cout<< v[ w[i] - 2 ] <<" "<< v[ w[i] ] <<" ";
            }
            cout<<"\n";
            cout.flush();
            cin>> s + 1;
        }
        for(i = 0; i < w.size(); i++){
            r[ w[i] ] = s[i + 1] - '0';
        }
        w.clear();
        val[1] = 1;
        val[2] = 2;
        for(i = 3; i <= nr; i++){
            if(r[i] == 1){
                val[i] = val[i - 2];
            }
            else{
                val[i] = 6 - val[i - 1] - val[i - 2];
            }
        }
        for(i = 1; i <= nr; i++){
            for(j = v[i]; j < v[i + 1]; j++){
                sol[ val[i] ].push_back(j);
            }
        }
        cout<<"A "<< sol[1].size() <<" "<< sol[2].size()<<" "<< sol[3].size() <<"\n";
        for(i = 1; i <= 3; i++){
            for(j = 0; j < sol[i].size(); j++){
                cout<< sol[i][j] <<" ";
            }
            cout<<"\n";
            sol[i].clear();
        }
        cout.flush();
    }
}