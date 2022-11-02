program code6;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean; 
var a:array[-1..100,-1..100]of char;
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
begin
 readln(n,m);
 for i:=1 to n do begin
  for j:=1 to m do
   read(a[i,j]);
  readln
 end
end;

procedure solve;
 var mini,maxi,minj,maxj,i,j:int;
begin
 mini:=maxint;
 maxi:=-maxint;
 minj:=maxint;
 maxj:=-maxint;

 for i:=1 to n do
  for j:=1 to m do
   if a[i,j]='*' then begin
    if i<mini then mini:=i;
    if i>maxi then maxi:=i;
    if j<minj then minj:=j;
    if j>maxj then maxj:=j
   end;

 for i:=mini to maxi do begin
  for j:=minj to maxj do write(a[i,j]);
  writeln
 end
end;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input,'input.txt');
 rewrite(output,'output.txt');
 {$ENDIF}
 readdata;
 solve
end.