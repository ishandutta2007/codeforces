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

const ll p = 1e9 + 7;

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
    
    int n;
    cin>>n;
    vector<int> p(n);
    vector<int> b(n);
    for (int i = 0; i<n; i++) {cin>>p[i]; p[i]--;}
    for (int i = 0; i<n; i++) cin>>b[i];
    int summ = 0;
    for (int i = 0; i<n; i++) summ+=b[i];
    summ++;
    summ%=2;
    
    int counter = 0;
    vector<bool> visited(n);
    for (int i = 0; i<n; i++) if (!visited[i])
    {
        counter++;
        int kek = i;
        while (!visited[kek]) 
        {
            visited[kek] = true;
            kek = p[kek];
        }
    }
    
    if (counter==1) cout<<summ;
    else cout<<counter+summ;
    

}