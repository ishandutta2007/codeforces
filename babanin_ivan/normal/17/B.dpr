program code4;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
type int=integer;
var a:array[0..1100,0..1100]of int;
    n,m:int;
    q:array[1..1100]of int;

procedure readdata;
 var i,x,y,z,j:int;
begin
 readln(n);
 for i:=1 to n do read(q[i]);
 readln;
 readln(m);
 for i:=1 to n do
  for j:=1 to n do
   a[i,j]:=maxint;
 for i:=1 to m do begin
  readln(x,y,z);
  a[y,x]:=min(a[y,x],z);
 end;
end;

procedure solve;
 var ans:array[1..1000]of int;
     max,i,j,x,y,k:int;
     f:boolean;
     sum:int64;
begin
 max:=-maxint;
 k:=0;
 for i:=1 to n do
  if q[i]>max then begin
   max:=q[i];
   k:=1;
  end
  else if q[i]=max then inc(k);
 if (k>1)or(m<n-1) then begin
  writeln(-1);
  halt(0)
 end;
 for i:=1 to n do
  ans[i]:=maxint;
 for i:=1 to n do
  if q[i]<>max then begin
   for j:=1 to n do
    ans[i]:=min(a[i,j],ans[i])
  end
  else ans[i]:=0;
 f:=false;
 sum:=0;
 for i:=1 to n do
  if (ans[i]=maxint)then f:=true
   else sum:=sum+ans[i];
 if f then begin
  writeln(-1);
  halt(0)
 end;
 writeln(sum);
end;

begin
 //reset(input,'input.txt');
// rewrite(output,'output.txt');
 readdata;
 solve
end.