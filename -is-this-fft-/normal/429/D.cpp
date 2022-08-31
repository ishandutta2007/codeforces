#include <iostream>
#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

const int MAX_LENGTH = 100005;
 
using namespace std;

/* A method of finding two closest points
 * Code copied from GeeksforGeeks XD */

// A structure to represent a Point in 2D plane
struct Point
{
    int x, y;
};
 
/* Following two functions are needed for library function qsort().
   Refer: http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
 
// Needed to sort array of points according to X coordinate
int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}
// Needed to sort array of points according to Y coordinate
int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}
 
// A utility function to find the distance between two points
double dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}
 
// A Brute Force method to return the smallest distance between two points
// in P[] of size n
double bruteForce(Point P[], int n)
{
    double min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}
 
// A utility function to find minimum of two double values
double min(double x, double y)
{
    return (x < y)? x : y;
}
 
 
// A utility function to find the distance beween the closest points of
// strip of given size. All points in strip[] are sorted accordint to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
double stripClosest(Point strip[], int size, double d)
{
    double min = d;  // Initialize the minimum distance as d
 
    qsort(strip, size, sizeof(Point), compareY); 
 
    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
 
    return min;
}
 
// A recursive function to find the smallest distance. The array P contains
// all points sorted according to x coordinate
double closestUtil(Point P[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(P, n);
 
    // Find the middle point
    int mid = n/2;
    Point midPoint = P[mid];
 
    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    double dl = closestUtil(P, mid);
    double dr = closestUtil(P + mid, n-mid);
 
    // Find the smaller of two distances
    double d = min(dl, dr);
 
    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;
 
    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    return min(d, stripClosest(strip, j, d) );
}
 
// The main functin that finds the smallest distance
// This method mainly uses closestUtil()
double closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);
 
    // Use recursive function closestUtil() to find the smallest distance
    return closestUtil(P, n);
}

int arr [MAX_LENGTH], cum [MAX_LENGTH];
Point pts [MAX_LENGTH];

int main () {
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  cum[0] = arr[0];
  for (int i = 1; i < length; i++) {
    cum[i] = cum[i - 1] + arr[i];
  }

  for (int i = 0; i < length; i++) {
    pts[i].x = i;
    pts[i].y = cum[i];
  }

  cout << fixed << setprecision(0) << closest(pts, length) * closest(pts, length) << endl;
}