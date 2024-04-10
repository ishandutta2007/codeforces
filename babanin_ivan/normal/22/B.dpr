program code6;

{$APPTYPE CONSOLE}
{$minstacksize 16000000}
uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean;
var a:array[-1..28,-1..28]of bool;
    b:array[-1..28,-1..28]of int;
    n,m:int;

procedure swap(var a,b:int);
 var c:int;
begin
 c:=a;
 a:=b;
 b:=c
end;

procedure readdata;
 var i,j:int;
     c:char;
begin
 readln(n,m);
 for i:=1 to n do begin
  for j:=1 to m do begin
   read(c);
   if c='1' then a[i,j]:=false
    else a[i,j]:=true;
  end;
  readln
 end;
end;

procedure solve;
 var max,i,j,z,min1,x:int;
begin
 max:=0;
 for i:=1 to n do
  for j:=1 to m do
   if a[i,j] then begin
    x:=j;
    b[i,j]:=0;
    while a[i,x] and(x<=m)do begin
     inc(b[i,j]);
     inc(x)
    end
   end;
 for i:=1 to n do
  for j:=1 to m do
   if a[i,j] then begin
   z:=i;
   min1:=b[i,j];
   while a[z,j] and (z<=n) do begin
    min1:=min(min1,b[z,j]);
    if (z-i+1)*2+2*min1 >max then max:=(z-i+1)*2+2*min1;
    inc(z);
   end;
  end;
 writeln(max);
end;

begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readdata;
 solve
end.