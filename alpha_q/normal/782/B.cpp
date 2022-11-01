#include <bits/stdc++.h>
#define eps     1e-6

using namespace std;

const int N = 60005;

double position[N];
double velocity[N];
int n;

double evaluate (double x) {
    double ret = 0.00;
    for (int j = 1; j <= n; j ++) {
        double distance = fabs (position[j] - x);
        double need = distance / velocity[j];
        ret = max (need, ret);
    }
    return ret;
}

double  TS (double left, double right){

    if (right - left < eps) return (left + right)/2.0;

    double leftThird = (2 * left + right)/3.0;
    double rightThird = (left + 2 * right)/3.0;

    if (evaluate (leftThird) > evaluate(rightThird)) return TS (leftThird, right);
    else return TS (left, rightThird);
}

int main () {
    scanf ("%d", &n);

    double M = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> position[i];
        M = max (M, position[i]);
    }

    for (int i = 1; i <= n; i ++) {
        cin >> velocity[i];
    }

    double answer = TS (0.00, (double) M);
    answer = evaluate(answer);

    printf ("%.10f\n", answer);

    return 0;
}