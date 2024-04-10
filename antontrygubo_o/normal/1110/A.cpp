#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

const ll p = 78294349;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int b, k;
    cin>>b>>k;
    vector<int> a(k);
    get(a);
    if (b%2==0)
    {
        if (a[k-1]%2==0) {cout<<"even"; return 0;}
        else {cout<<"odd"; return 0;}
    }
    int Sum = 0;
    for (int i = 0; i<k; i++) Sum = (Sum + a[i])%2;
    if (Sum%2==0) {cout<<"even"; return 0;}
    else {cout<<"odd"; return 0;}

}