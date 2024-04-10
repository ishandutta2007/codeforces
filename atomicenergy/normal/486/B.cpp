#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>

#include <vector>
#include <algorithm>
using namespace std;


bool testa(int a[100][100], int i, int m, int n){
    for(int j=0; j<n; j++){
        if(a[i][j]==0){
            return false;
        }
    }
    return true;
}

bool testb(int a[100][100], int i, int m, int n){
    for(int j=0; j<n; j++){
        if(a[j][i]==0){
            return false;
        }
    }
    return true;
}

bool testc(int a[100][100], int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]==1)
                return true;
        }
    }
    return false;
}

int main()
{
    int m,n;
    cin >> m >> n;
    int a[100][100];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    vector < int > v;
    vector < int > u;
    for (int i=0; i<m; i++){
        if(testa(a,i, m, n)){
            for(int j=0; j<n; j++){
                a[i][j]=2;
            }
            v.push_back(i);
            //cout << i << " ";
        }

    }
    //cout << endl;
    for (int i=0; i<n; i++){
        if(testb(a,i, n, m)){
            for(int j=0; j<m; j++){
                a[j][i]=2;
            }
            u.push_back(i);
            //cout << i << " ";
        }

    }
    //cout << endl;

    if(testc(a,m,n)){
        cout << "NO" << endl;
    }
    else if(u.size()==0 && v.size()==0){
        cout << "YES" << endl;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(j!=0)
                    cout <<" ";
                cout << "0";

            }
            cout << endl;
        }
    }
    else if(u.size()==0 || v.size()==0){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        int b[100][100];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                b[i][j]=0;
            }
        }
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<u.size(); j++){
                b[v[i]][u[j]]=1;
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(j!=0)
                    cout <<" ";
                cout << b[i][j];

            }
            cout << endl;
        }
    }
}