#include <bits/stdc++.h>

using namespace std;

int rt(long long d) {
    long long c=pow(d,1./3);
    while(c*c*c<=d) c++;
    while(c*c*c>d) c--;
    return c;
}

map<long long, pair<int,long long> > m;

pair<int,long long> megold(long long a) {
    if(a==0) return make_pair(0,0ll);
    if(m.find(a)!=m.end()) return m[a];
    long long c=rt(a);
    pair<int,long long> ki1=megold(c*c*c-1), ki2=megold(a-c*c*c);
    ki2.first++;
    ki2.second+=c*c*c;
    if(ki1.first>ki2.first || (ki1.first==ki2.first && ki1.second>ki2.second)) return m[a]=ki1;
    else return m[a]=ki2;
}

int main()
{
    long long a;
    cin >> a;
    pair<int,long long> ki=megold(a);
    cout << ki.first << " " << ki.second << endl;
    return 0;
}