#include <iostream>
#include <vector>
#include <algorithm>
//#include <math.h>
//#include <vector>
//#pragma optimize("g",on)
 
using namespace std;
 
#define Err .00000001
 
typedef double fpType;
 
//Geometry test
struct Vector3 {
	
	fpType x;
	fpType y;
	fpType z;
 
	Vector3() {
		x = y = z = 0;
	}
 
	Vector3(const fpType &a, const  fpType &b, const fpType &c) {
		x = a;
		y = b;
		z = c;
	}
 
	//O(8)
	Vector3 Normalized() {
		Vector3 tmp = *this;
		tmp.Normalize();
		return tmp;
	}
 
	//O(8)
	void Normalize() {
		fpType magnitude = Magnitude();
		if (magnitude == 0) {
			x = 1;
			y = 1;
			z = 1;
		}
		else
		{
			x /= magnitude;
			y /= magnitude;
			z /= magnitude;
		}
	}
 
	//O(7)
	fpType Magnitude() {
		return sqrt(x * x + y * y + z * z);
	}
 
	//Math
 
	Vector3 operator + (const Vector3 &b)const {
		Vector3 tmp = *this;
		tmp.x += b.x;
		tmp.y += b.y;
		tmp.z += b.z;
		return tmp;
	}
 
	Vector3 operator - (const Vector3 &b)const {
		Vector3 tmp = *this;
		tmp.x -= b.x;
		tmp.y -= b.y;
		tmp.z -= b.z;
		return tmp;
	}
 
	Vector3 operator * (const Vector3 &b)const {
		Vector3 tmp = *this;
		tmp.x *= b.x;
		tmp.y *= b.y;
		tmp.z *= b.z;
		return tmp;
	}
 
	Vector3 operator * (const fpType &b)const {
		Vector3 tmp = *this;
		tmp.x *= b;
		tmp.y *= b;
		tmp.z *= b;
		return tmp;
	}
 
	Vector3 operator / (const Vector3 &b)const {
		Vector3 tmp = *this;
		tmp.x /= b.x;
		tmp.y /= b.y;
		tmp.z /= b.z;
		return tmp;
	}
 
	Vector3 operator / (const fpType &b)const {
		Vector3 tmp = *this;
		tmp.x /= b;
		tmp.y /= b;
		tmp.z /= b;
		return tmp;
	}
 
	bool operator == (const Vector3 &b)const {
		return b.x == x && b.y == y && b.z == z;
	}
 
	bool operator != (const Vector3 &b)const {
		return b.x != x || b.y != y || b.z != z;
	}
 
	//O(5)
	static fpType Dot(const Vector3 &a, const Vector3 &b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}
 
	//O(9)
	static Vector3 Cross(const Vector3 &a, const Vector3 &b) {
		Vector3 tmp = Vector3{ a.y * b.z - a.z * b.y,a.z * b.x - a.x * b.z,a.x * b.y - a.y * b.x };
		return tmp;
	}
 
	static Vector3 Nan() { return Vector3{ -100000000,-100000000,-100000000 }; };
 
};
 
Vector3 p1Vertices[100000];
Vector3 p2Vertices[100000];
 
struct Line {
	Vector3 origin;
	Vector3 direction;
	fpType length;
 
	Line() {
		origin = Vector3{ 0,0,0 };
		direction = Vector3{ 0,1,0 };
		length = 0;
	}
 
	Line(const Vector3 &s, const  Vector3 &d, const  fpType &l) {
		origin = s;
		direction = d;
		length = l;
	}
};
 
struct Plane {
	Vector3 origin;
	Vector3 normal;
 
	Plane() {
		origin = Vector3{};
		normal = Vector3{ 0,1,0 };
	}
 
	Plane(const Vector3& o, const Vector3& n) {
		origin = o;
		normal = n;
	}
 
	Plane(const Vector3& a, const Vector3& b, const Vector3& c) {
		origin = b;
		Vector3 deltaA = (b - a); deltaA.Normalize();
		Vector3 deltaB = (c - b); deltaB.Normalize();
		normal = Vector3::Cross(deltaA, deltaB);
		normal.Normalize();
	}
 
	struct IntersectionData {
		Vector3 pos;
		bool direction;
 
		IntersectionData()
		{
			pos = Vector3::Nan();
			direction = false;
		}
 
		IntersectionData(Vector3 p, bool d) {
			pos = p;
			direction = d;
		}
	};
 
	//O(32)
	IntersectionData IntersectionWithLine(const Line &l) {
		fpType dotProduct = Vector3::Dot(normal, l.direction);
 
		if (dotProduct == 0)
		{
			return IntersectionData{ Vector3::Nan(),false };
		}
 
		fpType t = (Vector3::Dot(normal, origin) - Vector3::Dot(normal, l.origin)) / dotProduct;
		Vector3 cp = (l.origin + l.direction * t);
		if (t <= l.length && t >= 0)
		{
			return IntersectionData{ cp, dotProduct < 0 };
		}
		return IntersectionData{ Vector3::Nan(),false };
	}
 
	//O(32)
	IntersectionData IntersectionWithLine(const Line &ppl, const  Line &pl, const  Line &l) {
		fpType dotProduct = Vector3::Dot(normal, l.direction);
		if (dotProduct == 0)
		{
			return IntersectionData{ Vector3::Nan(),false };
		}
 
		fpType t = (Vector3::Dot(normal, origin) - Vector3::Dot(normal, l.origin)) / dotProduct;
 
		Vector3 ep = l.origin + l.direction * l.length;
 
		Vector3 cp = (l.origin + l.direction * t);
		//cout << "\t" << t << " " << l.length << " => " << cp.x << " " << cp.y << " " <<cp.z <<'\n';
		if (t < l.length - Err && t >= -Err)
		{
			fpType dotMp = Vector3::Dot(l.direction, normal) * Vector3::Dot(pl.direction, normal);
			if (t > Err || dotMp > 0 || dotMp == 0 && Vector3::Dot(l.direction, normal) * Vector3::Dot(ppl.direction, normal) > 0)
				return IntersectionData{ cp, dotProduct < 0 };
		}
		return IntersectionData{ Vector3::Nan(),false };
	}
 
};
 
struct Poligon {
	vector<Vector3> vertices;
	int vCount = 0;
	vector<Line> lines;
	int lCount = 0;
	//O(1)
	void AddVertex(const Vector3 &v) {
		vertices.push_back(v);
		//vertices[vCount] = v;
		vCount++;
	}
 
	//O(19n)
	void CalculateLines()
	{
		for (int i = 0; i < vCount; i++)
		{
			int nI = (i == vCount - 1 ? 0 : i + 1);
			Vector3 direction = vertices[nI] - vertices[i];
			fpType directionMag = direction.Magnitude();
			direction = direction / directionMag;
			Line newLine = Line{ vertices[i],direction,directionMag };
			lines.push_back(newLine);
			//lines[lCount] = newLine;
			lCount++;
		}
	}
 
	//O(9)
	Plane CalculatePlane()const {
		Plane res = Plane{ vertices[0],vertices[1],vertices[2] };
		return res;
	}
 
	//O(20 + 130n + 2 n log(n))
	bool IntersectsWith(Poligon &b, bool isReversed = false) {
		//Important Log
		//cout << "\nStating New Calc \n  V\n";
 
		Plane aPlane = CalculatePlane();
		Plane bPlane = b.CalculatePlane();
 
		if (bPlane.normal == aPlane.normal)
		{
			return false;
		}
 
		bool foundSth = false;
		bool upToNowDirection = false;
 
		vector<int> collidingLines;
		vector<Vector3> collidingPositions;
		//19
 
		//O(36n)
		//{
		for (int i = 0; i < b.lCount; i++)
		{
			Line l = b.lines[i];
			Vector3 cp = aPlane.IntersectionWithLine(l).pos;
			if (cp.x > -100000000 && cp.y > -100000000 && cp.z > -100000000)
			{
				collidingPositions.push_back(cp);
				collidingLines.push_back(i);
			}
		}
		//}
		vector<vector<Vector3>::iterator> where2ErrPoint;
 
		//O(31n)
		//{
		for (int i = collidingPositions.size() - 1; i >= 0; i--)
		{
			if (b.lines[collidingLines[i]].origin == collidingPositions[i] || b.lines[collidingLines[i]].origin + b.lines[collidingLines[i]].direction * b.lines[collidingLines[i]].length == collidingPositions[i])
			{
				int secI = (i == collidingPositions.size() - 1 ? 0 : collidingLines[i] + 1);
				fpType dotProdA = Vector3::Dot(b.lines[collidingLines[i]].direction, aPlane.normal);
 
				fpType dotProdB = Vector3::Dot(b.lines[collidingLines[i] == b.lCount - 1 ? 0 : collidingLines[i] + 1].direction, aPlane.normal);
				if (dotProdA * dotProdB <= 0)
				{
					where2ErrPoint.push_back(collidingPositions.begin() + i);
				}
			}
		}//n
		for (auto ptr : where2ErrPoint)
		{
			collidingPositions.erase(ptr);
		}
		//}
 
		vector<fpType> collisionDistances = {};
 
		Line planeIntersectionLine;
		if (collidingPositions.size() == 0) {
			return false;
		}
		planeIntersectionLine.origin = collidingPositions[0];
		planeIntersectionLine.direction = Vector3::Cross(aPlane.normal, bPlane.normal).Normalized();
		planeIntersectionLine.origin = planeIntersectionLine.origin - planeIntersectionLine.direction * 100000000;
 
		//O(n)
		//{
		for (Vector3 p : collidingPositions)
		{
			collisionDistances.push_back((p - planeIntersectionLine.origin).Magnitude());
		}
		//}
 
		//O(n log(n))
		//{
		sort(collisionDistances.begin(), collisionDistances.end());
		//}
 
 
		//Main
		//O(56n + n log(n))
		//{
		//cout << "hello\n";
		for (int i = 0; i < lCount; i++) {
			Line l = lines[i];
			Line pl;
			Line ppl;
			Plane::IntersectionData calcRes;
			if (i == 0)
				pl = lines[lCount - 1];
			else
				pl = lines[i - 1];
			if (i == 1)
				ppl = lines[lCount - 1];
			else if (i == 0)
				ppl = lines[lCount - 2];
			else
				ppl = lines[i - 2];
 
			calcRes = bPlane.IntersectionWithLine(ppl, pl, l);
			if (calcRes.pos.x > -100000000 && calcRes.pos.y > -100000000 && calcRes.pos.z > -100000000)
			{
				//cout << calcRes.pos.x << " " << calcRes.pos.y << " " << calcRes.pos.z << '\n';
				bool pointInside = false;
 
				int checkingRangeMax = collisionDistances.size() - 1, checkingRangeMin = 0;
				fpType calcResTime = (planeIntersectionLine.origin - calcRes.pos).Magnitude();
				if (checkingRangeMax - checkingRangeMin > 1)
				{
					if (calcResTime > collisionDistances[0] && calcResTime < collisionDistances.back())
					{
						//O(log(n))
						while (checkingRangeMax - checkingRangeMin > 1)
						{
							int currentIndex = (checkingRangeMax + checkingRangeMin) / 2;
 
							if (calcResTime > collisionDistances[currentIndex])
							{
								checkingRangeMin = currentIndex;
							}
							else
							{
								checkingRangeMax = currentIndex;
							}
						}
 
						if (checkingRangeMin % 2 == 0)
						{
							pointInside = true;
						}
					}
				}
				else if (checkingRangeMax - checkingRangeMin == 1)
				{
					if (calcResTime > collisionDistances[0] && calcResTime < collisionDistances[1])
					{
						pointInside = true;
					}
				}
				if (pointInside)
				{
					//Most Important Log
					//cout << "" << calcRes.pos.x << " " << calcRes.pos.y << " " << calcRes.pos.z << "\n";
					if (foundSth) {
						if (upToNowDirection != calcRes.direction)
						{
							if (!isReversed)
								return b.IntersectsWith(*this, true);
							else
								return false;
						}
					}
					foundSth = true;
					upToNowDirection = calcRes.direction;
				}
			}
		}
		//}
		if (foundSth)
			return true;
		else if (!isReversed)
			return b.IntersectsWith(*this, true);
		return false;
	}
};
 
Poligon p1, p2;
 
int main() {
	int n1;
	cin >> n1;
	for (int i = 0; i < n1; i++)
	{
		scanf_s("%lf %lf %lf", &p1Vertices[i].x, &p1Vertices[i].y, &p1Vertices[i].z);
		//cin >> p1Vertices[i].x >> p1Vertices[i].y >> p1Vertices[i].z;
	}
	int n2;
	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		scanf_s("%lf %lf %lf", &p2Vertices[i].x, &p2Vertices[i].y, &p2Vertices[i].z);
		//cin >> p2Vertices[i].x >> p2Vertices[i].y >> p2Vertices[i].z;
	}
 
	p1 = Poligon{};
	p2 = Poligon{};
 
	for (int i = 0; i < n1; i++)
	{
		p1.AddVertex(p1Vertices[i]);
	}
	p1.CalculateLines();
	for (int i = 0; i < n2; i++)
	{
		p2.AddVertex(p2Vertices[i]);
	}
	p2.CalculateLines();
	if (p1.IntersectsWith(p2)) {
		cout << "YES";
		return 0;
	}
	else
	{
		cout << "NO";
		return 0;
	}
 
}