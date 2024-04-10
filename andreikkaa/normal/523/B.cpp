/**
    inline void print_hello()
    {
        string message = R"(Hello!

        My name is Andrey E. Kalendarov,
        And I'm waiting for OK (or AC) status.

        Yes, please, don't blame my code.
        I know that it's far from ideal.
        But it should pass all the tests.

        And everybody will be happy.
        And you, my dear reader, too.
        I'm sure.

        Goodbye.)";

        cout << message << endl;
    }
**/

/* _____ INCLUDES _____ */

// ===== IO, STRINGS SECTION =====

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>

// ===== STL SECTION =====

#include <algorithm>
#include <array>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

// ===== OTHER LIBS SECTION =====

#include <math.h>
#include <stdlib.h> // RANDOM IS MY HOME!!!
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <memory.h>

/* _____ SPECIAL FEATURES _____ */

using namespace std;

/* _____ CODE _____ */

long long a[200001];
long long part[200001];
long long q[200001];
long double mean[200001];

int main()
{
    int n, t;
    long double c;
    cin >> n >> t >> c;

    part[0] = 0;

    for(int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        part[i] = part[i - 1] + a[i];
    }

    mean[0] = 0;

    for(int i = 1; i <= n; ++i)
    {
        mean[i] = (mean[i - 1] + a[i] / (long double) t) / c;
    }


    int m;
    cin >> m;

    cout.precision(14);

    for(int i = 1; i <= m; ++i)
    {
        int q;
        scanf("%d", &q);
        long double real = (part[q] - part[q - t]) / (long double) t;
        long double approx = mean[q];
        long double error = fabs(approx - real) / real;
        cout << real << " " << approx << " " << error << endl;
    }

    return 0;
}