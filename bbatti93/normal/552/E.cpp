#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <cstdlib>
#include <cmath>

using namespace std;

int a,n,b[10000], tol[3000], ig[3000];
long long t[3000][3000], v[3000][3000];
string s;
char c[3000];

int main()
{
    cin >> s;
    int n=s.length()/2+1;
    for(int i=0;i<n-1;i++) {
        b[i]=s[2*i]-'0';
        c[i+1]=s[2*i+1];
    }
    b[n-1]=s[2*n-2]-'0';
    for(int i=0;i<n;i++) {
        t[i+1][i]=1;
        t[i][i]=v[i][i]=b[i];
        for(int j=i+1;j<n;j++) {
            if(c[j]=='+') {
                v[i][j]=b[j];
                t[i][j]=b[j]+t[i][j-1];
            } else {
                v[i][j]=v[i][j-1]*b[j];
                t[i][j]=t[i][j-1]+(b[j]-1)*v[i][j-1];
            }
        }
    }
    tol[0]=0;
    ig[n-1]=n-1;
    for(int i=1;i<n;i++) {
        if(c[i]=='+') {
            tol[i]=i;
        } else {
            tol[i]=tol[i-1];
        }
    }
    for(int i=n-2; i>=0;i--) {
        if(c[i+1]=='+') {
            ig[i]=i;
        } else {
            ig[i]=ig[i+1];
        }
    }
    long long ki=0;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            long long most;
            int a=tol[i];
            int b=ig[j];
            if(i>0) most=t[i][j]*t[a][i-1]*t[j+1][b];
            else most=t[i][j]*t[j+1][b];
            if(a>0) most+=t[0][a-1];
            if(b<n-1) most+=t[b+1][n-1];
            if(most>ki) ki=most;
        }
    }
    cout << ki;
    return 0;
}