program code7;

{$APPTYPE CONSOLE}
{$R-,Q-}
uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean;
const hash=997;
var n:int;
    d:array[-1..400,-1..400]of int64;

procedure swap(var a,b:int);
 var c:int;
begin
  c:=a;
  a:=b;
  b:=c
end;

procedure writedata;
 var i,j:int;
     ans:int64;
begin
  ans:=0;
  for i:=1 to n do
    for j:=1 to n do
      inc(ans,d[i,j]);
  write(ans div 2,' ')
end;

procedure modify(a,b,c:int);
 var i,j:int;
begin
  d[a,b]:=c;
  d[b,a]:=c;
  for i:=1 to n do
    for j:=1 to n do
      if (i<>j)then begin
        d[i,j]:=min(d[i,j],d[i,a]+d[a,b]+d[b,j]);
        d[i,j]:=min(d[i,j],d[j,a]+d[a,b]+d[b,i])
      end
end;

procedure readdata;
 var i,k,j,a,b,c:int;
begin
  readln(n);
  for i:=1 to n do begin
    for j:=1 to n do
      read(d[i,j]);
    readln
  end;

  readln(k);
  for i:=1 to k do begin
    readln(a,b,c);
    if d[a,b]>c then modify(a,b,c);
    writedata
  end
end;

begin
  {$IFNDEF ONLINE_JUDGE}
  reset(input,'input.txt');
  rewrite(output,'output.txt');
  {$ENDIF}
  readdata
end.