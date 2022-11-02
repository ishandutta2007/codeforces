program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
type int=integer;
var l,r:array[1..200]of int;
    ans,i,n,p2,p1,p3,t1,t2:int;

begin
 readln(n,p1,p2,p3,t1,t2);
 for i:=1 to n do
  readln(l[i],r[i]);
 ans:=0;
 for i:=1 to n do
  ans:=ans+(r[i]-l[i])*p1;
 for i:=1 to n-1 do
  if (l[i+1]-r[i])>=t1 then ans:=ans+p1*t1
   else ans:=ans+p1*(l[i+1]-r[i]);
 for i:=1 to n-1 do
  if (l[i+1]-r[i])>t1 then
   if (l[i+1]-r[i]-t1)<=t2 then inc(ans,p2*(l[i+1]-r[i]-t1))
    else inc(ans,p2*t2);
 for i:=1 to n-1 do
  if (l[i+1]-r[i])>t1+t2 then
   inc(ans,p3*(l[i+1]-r[i]-t1-t2));
 writeln(ans);
end.