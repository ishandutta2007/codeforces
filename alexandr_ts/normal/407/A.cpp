#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const int MAXN = 1000000;

vector <int> a1;
vector <int> a2;
vector <int> b2;
vector <int> b1;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a, b;
    cin >> a >> b;
    for(int i = 1; i < a; i++)
    {
        if((int)(sqrt(a * a - i * i + EPS)) * (int)(sqrt(a * a - i * i) + EPS) == a * a - i * i)
        {a1.push_back(i); a2.push_back((int)(sqrt(a * a - i * i + EPS)));}
    }
    for(int i = 1; i < b; i++)
    {
        if((int)(sqrt(b * b - i * i + EPS)) * (int)(sqrt(b * b - i * i) + EPS) == b * b - i * i)
        {b1.push_back(i); b2.push_back((int)(sqrt(b * b - i * i + EPS)));}
    }
    for(int i = 0; i < a1.size(); i++)
        for(int j = 0; j < b1.size(); j++)
        {
            if(a1[i] < a2[i])
                swap(a1[i], a2[i]);
            if(b1[j] < b2[j])
                swap(b1[j], b2[j]);
            if(a1[i] * b2[j] == a2[i] * b1[j])
            {
                cout << "YES" << endl;
                if(a1[i] != b2[j])
                cout << "0 0" << endl << a1[i] << " " << a2[i] << endl << b2[j] << " " << -b1[j];
                else
                cout << "0 0" << endl << a1[i] << " "  << a2[i] << endl << -b2[j] << " " << b1[j];
                return 0;
            }
        }
    cout << "NO";

    return 0;
}