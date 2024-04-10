#include <iostream>

using namespace std;

const int NMAX = 100005;
int say[NMAX];

int guilty[NMAX]; //guilty[i] = how many people have said i is guilty
int not_guilty[NMAX]; //not_guilty[i] = how many people have said i is NOT guilty

bool criminal[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    m = n - m; //Work with those which lied

    for (int i = 1; i <= n; ++ i)
        cin >> say[i];

    int total_guilty = 0;
    for (int i = 1; i <= n; ++ i)
        if (say[i] > 0)
            ++ guilty[say[i]], ++ total_guilty;
        else
            ++ not_guilty[-say[i]];

    int criminals = 0;
    for (int i = 1; i <= n; ++ i)
        if (total_guilty - guilty[i] + not_guilty[i] == m) //That's how many people lied
            criminal[i] = true, ++ criminals;

    if (criminals == 1) {
        for (int i = 1; i <= n; ++ i)
            if (say[i] > 0) {
                if (criminal[say[i]])
                    cout << "Truth" << '\n';
                else
                    cout << "Lie" << '\n';
            }
            else {
                if (!criminal[-say[i]])
                    cout << "Truth" << '\n';
                else
                    cout << "Lie" << '\n';
            }
    }
    else {
        for (int i = 1; i <= n; ++ i)
            if (say[i] > 0) {
                if (criminal[say[i]])
                    cout << "Not defined" << '\n';
                else
                    cout << "Lie" << '\n';
            }
            else {
                if (!criminal[-say[i]])
                    cout << "Truth" << '\n';
                else
                    cout << "Not defined" << '\n';
            }
    }

    return 0;
}