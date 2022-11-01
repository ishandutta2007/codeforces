#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
    int kol[10000];
long long a[1000000];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    if(n == 1)
    {
        cout << -1;
        return 0;
    }

    int qua1 = 0;
    int a1 = a[0] - a[1];
    int qua2 = 0;
    int a2 = 1000000000;
    vector <int> v;
    vector <int> ps;

    for(int i = 0; i < n - 1; i++)
    {
        bool finn = false;
        int posss = 0;
        for(int j = 0; j < v.size(); j++)
            if(a[i + 1] - a[i] == v[j]){
                finn = true; posss = j;}
        if(!finn){
            v.push_back(a[i + 1] - a[i]);
            ps.push_back(i);
            kol[v.size() - 1] = 1;}
        else
            kol[posss]++;
    }
    if(v.size() >= 3)
    {
        cout<< 0;
        return 0;
    }
    if(v.size() == 1)
    {
        if(n == 2)
            if((abs(v[0]) % 2) == 0){
                if(v[0] == 0)
                    cout << 1 << endl << a[0];
                else
                    cout << 3 << endl << a[0] - v[0] << " " << a[0] + v[0] / 2 << " " << a[1] + v[0];
                return 0;}
            else{
                cout << 2 << endl << a[0] - v[0] << " " << a[1] + v[0];
                return 0;}
        else
        {
            if(v[0] == 0 && a[0] == a[n - 1])
                cout << 1 << endl << a[0];
            else
                cout << 2 << endl << a[0] - v[0] << " " << a[n - 1] + v[0];
            return 0;
        }
    }

    else
    {
        //cout << endl << v[0] << " " << v[1] << endl << endl;
        //cout << endl << kol[0] << " " << kol[1] << endl << endl;
        if(v[1] == 2 * v[0])
        {
            if(kol[1] == 1){
                cout << 1 << endl << a[ps[1]] + v[0];
                return 0;}
            else
            {
                cout << 0;
                return 0;
            }
        }

        if(v[0] == 2 * v[1])
        {
            if(kol[0] == 1){
                cout << 1 << endl << a[ps[0]] + v[1];
                return 0;}
            else
            {
                cout << 0;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}