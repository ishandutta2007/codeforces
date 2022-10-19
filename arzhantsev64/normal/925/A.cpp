#include <stdio.h>

const int INF = 1e9;

int abs(int x) {
return x > 0 ? x : -x;
}

int min(int a, int b) {
return a > b ? b : a;
}

int main() {
int n, m, cl, ce, v;
scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
int l[cl], e[ce];
for (int i = 0; i < cl; i++) {
scanf("%d", &l[i]);
}
for (int i = 0; i < ce; i++) {
scanf("%d", &e[i]);
}
int q;
scanf("%d", &q);
for (int _ = 0; _ < q; _++) {
int x1, y1, x2, y2;
scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
if (y1 == y2) {
printf("%d\n", abs(x2 - x1));
continue;
}
int left = -1, right = cl;
while (left < right - 1) {
int y = left + (right - left) / 2;
if (l[y] <= x1) {
left = y;
} else {
right = y;
}
}
int ans = INF;
if (left != -1) {
ans = min(ans, abs(x2 - l[left]) + abs(l[left] - x1) + abs(y2 - y1));
}
if (right != cl) {
ans = min(ans, abs(x2 - l[right]) + abs(l[right] - x1) + abs(y2 - y1));
}
left = -1, right = cl;
while (left < right - 1) {
int y = left + (right - left) / 2;
if (l[y] <= x2) {
left = y;
} else {
right = y;
}
}
if (left != -1) {
ans = min(ans, abs(x2 - l[left]) + abs(l[left] - x1) + abs(y2 - y1));
}
if (right != cl) {
ans = min(ans, abs(l[right] - x2) + abs(l[right] - x1) + abs(y2 - y1));
}
left = -1, right = ce;
while (left < right - 1) {
int y = left + (right - left) / 2;
if (e[y] <= x1) {
left = y;
} else {
right = y;
}
}
if (left != -1) {
ans = min(ans, abs(x2 - e[left]) + abs(e[left] - x1) + (abs(y2 - y1) + v - 1) / v);
}
if (right != ce) {
ans = min(ans, abs(x2 - e[right]) + abs(e[right] - x1) + (abs(y2 - y1) + v - 1) / v);
}
left = -1, right = ce;
while (left < right - 1) {
int y = left + (right - left) / 2;
if (e[y] <= x2) {
left = y;
} else {
right = y;
}
}
if (left != -1) {
ans = min(ans, abs(x2 - e[left]) + abs(e[left] - x1) + (abs(y2 - y1) + v - 1) / v);
}
if (right != ce) {
ans = min(ans, abs(e[right] - x1) + abs(x2 - e[right]) + (abs(y2 - y1) + v - 1) / v);
}
printf("%d\n", ans);
}
return 0; 
}