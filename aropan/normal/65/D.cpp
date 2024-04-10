#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>


using namespace std;


const string s[4] = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};

vector <int> a;
set < vector < int > > S[2];
set < vector < int > > *sin, *sout;
set < vector < int > > :: iterator x;
bool f[4];
int n;

int move(int I)
{
    for (int i = 0; i < 4; i++)
        a[i] = (*x)[i];
    a[I]--;
    if (a[I] < 0)
        for (int i = 0; i < 4; i++)
            a[i]++;

    (*sout).insert(a);
    return 0;
}

int main()
{
/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/
    sin = &(S[0]);
    sout = &(S[1]);

    a.resize(4);
    for (int i = 0; i < 4; i++)
        a[i] = 0;

    (*sout).insert(a);

    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        swap(sin, sout);
        (*sout).clear();
        char c;

        scanf("%c", &c);

        for (x = (*sin).begin(); x != (*sin).end(); x++)
        {
            switch (c)
            {
                case 'G': move(0); break;
                case 'H': move(1); break;
                case 'R': move(2); break;
                case 'S': move(3); break;
            }
            if (c != '?') continue;

            int m = 0;
            for (int i = 0; i < 4; i++)
                m = max(m, (*x)[i]);

            for (int i = 0; i < 4; i++)
                if ((*x)[i] == m) move(i);
        }
    }

    for (x = (*sout).begin(); x != (*sout).end(); x++)
    {
            int m = 0;
            for (int i = 0; i < 4; i++)
                m = max(m, (*x)[i]);

            for (int i = 0; i < 4; i++)
                f[i] |= ((*x)[i] == m);
    }

    for (int i = 0; i < 4; i++)
        if (f[i])
            cout << s[i] << endl;
    return 0;
}