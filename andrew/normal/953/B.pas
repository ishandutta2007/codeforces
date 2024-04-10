var
 a,b: array[1..100000] of int64;
 i, j : longint;
 k,  n, ans : int64;
procedure swap(var a,b:int64);
var c:int64;
begin
 c:=a;
 a:=b;
 b:=c;
end;
procedure sort(l,r:longint);
var i,j:longint;
m:int64;
begin
 i:=l;
 j:=r;
 m:=a[l+random(r-l+1)];
 repeat
  while a[i]<m do inc(i);
  while a[j]>m do dec(j);
  if i>j then break;
  swap(a[i],a[j]);
  inc(i); dec(j);
 until i>j;
 if i<r then sort(i,r);
 if l<j then sort(l,j);
end;

function gcd(a, b:int64) : int64;
begin
   while(a > 0) and (b > 0) do
   begin
    if a > b then a:= a mod b 
    else b:= b mod a;
   end;
   gcd:= a + b;
end;

begin
 randomize();
 readln(n);
 for i:=1 to n do read(a[i]);
 sort(1,n);
 for i:=1 to n-1 do b[i]:=a[i + 1] - a[i];
 k:= 0;
 for i:=1 to n-1 do k:= gcd(b[i],k);
 for i:=1 to n-1 do ans:= ans + b[i] div k - 1;
 writeln(ans);
end.