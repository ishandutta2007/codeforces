#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXL = 100007;
char s[MAXL];
int a[10], b[10];


pair <int, pair <string, string> > answer;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    gets(s);
    int l = strlen(s);
    if (l == 1)
    {
        puts(s);
        return 0;
    }

    sort(s, s + l);
    for (answer.first = 0; s[answer.first] == '0' && answer.first < l; answer.first++);
    reverse(s, s + l);
    answer.second = make_pair(s, s);
    for (int x = 1; x < 10; x++)
    {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < l; i++)
            a[s[i] - '0']++;
        for (int i = 0; i < 10; i++)
            b[i] = a[i];

        if (a[x] && b[10 - x])
        {
            string A, B;
            A.reserve(l);
            B.reserve(l);
            A = B = "";
            a[x]--;
            b[10 - x]--;
            A += x + '0';
            B += (10 - x) + '0';

            int k = 1;
            for (int i = 0; i < 10; i++)
                while (a[i] && b[9 - i])
                {
                    A += i + '0';
                    B += (9 - i) + '0';
                    k++;
                    a[i]--;
                    b[9 - i]--;
                }

            for (int j = 1; j < 10; j++)
                while (a[j]--) A += j + '0';

            for (int j = 1; j < 10; j++)
                while (b[j]--) B += j + '0';
/*
            cout << A << endl;
            cout << B << endl;
//*/
            int d = min(a[0], b[0]);
            while (a[0] > d) A += '0', a[0]--;
            while (b[0] > d) B += '0', b[0]--;

            k += d;
            reverse(A.begin(), A.end());
            reverse(B.begin(), B.end());
            while (a[0]--) A += '0';
            while (b[0]--) B += '0';
/*
            cout << A << endl;
            cout << B << endl;
            cout << endl;
//*/
            pair <int, pair <string, string> > curr = make_pair(k, make_pair(A, B));
            if (curr > answer) answer = curr;
        }
    }
//    printf("%d\n", answer.first);
    printf("%s\n%s\n", answer.second.first.c_str(), answer.second.second.c_str());
    return 0;
}