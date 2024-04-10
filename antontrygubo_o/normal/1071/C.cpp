#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 1e9 + 7;

vector<int> a;
int n;

struct ans
{
    int x;
    int y;
    int z;
};

vector<ans> my;

void f(int x, int y, int z)
{
    a[x] = 1-a[x];
    a[y] = 1-a[y];
    a[z] = 1-a[z];
    ans temp;
    temp.x = x;
    temp.y = y;
    temp.z = z;
    my.push_back(temp);
}

void op(int k)
{
    if (k>=n-10) return;
    else if (a[k]==0) op(k+1);
    else if (a[k+1]==0&&a[k+2]==0) {f(k, k+3, k+6); op(k+3);}
    else if (a[k+1]==1&&a[k+2]==1) {f(k, k+1, k+2); op(k+3);}
    else if (a[k+1]==0&&a[k+2]==1) {f(k, k+2, k+4); op(k+3);}
    else if (a[k+1]==1&&a[k+2]==0)
    {
        if (a[k+3]==0&&a[k+4]==0&&a[k+5]==0) {f(k, k+4, k+8); f(k+1, k+4, k+7); op(k+6);} 
        else if (a[k+3]==0&&a[k+4]==0&&a[k+5]==1) {f(k+1, k+3, k+5); f(k, k+3, k+6); op(k+6);}
        else if (a[k+3]==0&&a[k+4]==1&&a[k+5]==0) {f(k, k+1, k+2); f(k+2, k+4, k+6); op(k+6);}
        else if (a[k+3]==0&&a[k+4]==1&&a[k+5]==1) {f(k, k+4, k+8); f(k+1, k+5, k+9); op(k+6);}
        else if (a[k+3]==1&&a[k+4]==0&&a[k+5]==0) {f(k+1, k+3, k+5); f(k, k+5, k+10); op(k+6);}
        else if (a[k+3]==1&&a[k+4]==0&&a[k+5]==1) {f(k, k+3, k+6); f(k+1, k+5, k+9); op(k+6);}
        else if (a[k+3]==1&&a[k+4]==1&&a[k+5]==0) {f(k, k+3, k+6); f(k+1, k+4, k+7); op(k+6);}
        else if (a[k+3]==1&&a[k+4]==1&&a[k+5]==1) {f(k+1, k+3, k+5); f(k, k+4, k+8); op(k+6);} 
    }
}

void op2(int k)
{
    if (k>=n-4) return;
    else if (a[k]==0) op2(k+1);
    else if (a[k+1]==0&&a[k+2]==0) {f(k, k+2, k+4); op2(k+2);}
    else if (a[k+1]==1&&a[k+2]==1) {f(k, k+1, k+2); op2(k+3);}
    else if (a[k+1]==0&&a[k+2]==1) {f(k, k+2, k+4); op2(k+3);}
    else if (a[k+1]==1&&a[k+2]==0) {f(k, k+1, k+2); op2(k+2);}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    a.resize(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    op(0);
    
    op2(0);
    if (n>=4&&a[n-4]==1) f(n-4, n-3, n-2);
    if (n>=3&&a[n-3]==1) f(n-3, n-2, n-1);
    
    if (a[n-2]==1)
    {
        if (n<=7) {cout<<"NO"; return 0;}
        else {f(n-2, n-5, n-8); f(n-8, n-7, n-6); f(n-7, n-6, n-5);}
    }
    
    if (a[n-1]==1)
    {
        if (n<=6) {cout<<"NO"; return 0;}
        else {f(n-1, n-4, n-7); f(n-7, n-6, n-5); f(n-6, n-5, n-4);}
    }
    cout<<"YES"<<endl;
    cout<<my.size()<<endl;
    for (int i = 0; i<my.size(); i++) cout<<my[i].x+1<<' '<<my[i].y+1<<' '<<my[i].z+1<<endl;
}