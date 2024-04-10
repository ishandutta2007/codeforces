#include <bits/stdc++.h>

using namespace std;

const long long N = 1000000000;
vector<long long> great;
int max2(long long x)
{
    x++;
    int count = 0;
    while (x) {count++; x/=2;}
    return count-1;
}

int main() 
{
long long x;
cin>>x;
long long idx = 1;
while (x)
{
    int g = max2(x);
    for (int i = 0; i<g; i++) great.push_back(idx);
    x-=((1<<g)-1);
    idx+=N;
}
cout<<great.size()<<endl;
for (int i= 0; i<great.size(); i++) cout<<great[i]<<' ';


}