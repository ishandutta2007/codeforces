#include <iostream>

using namespace std;

int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

bool two(int n)
{
    return ((n&(n-1))==0);
}

int main()
{
    int saved[26]={0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
    int q;
    cin >> q;
    while(q--)
    {
        int a;
        cin >> a;
        int i=0;
        while((1<<(i+1))<=a) i++;
        if(!two(a+1)) cout << (1<<(i+1))-1 << endl;
        else cout << saved[i+1] << endl;
    }
    return 0;
}