program code8;

{$APPTYPE CONSOLE}
{$R+,Q+}
uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean;
const hash=997;
var a:array[1..2,-1..510]of int;
    l,ans:array[-1..510]of int;
    used:array[-1..510]of bool;
    n,m:int;

procedure swap(var a,b:int);
 var c:int;
begin
  c:=a;
  a:=b;
  b:=c
end;

procedure readdata;
 var i:int;
begin
  readln(n,m);
  for i:=1 to n do
    readln(a[1,i],a[2,i]);
  a[1,0]:=a[1,n];
  a[2,0]:=a[2,n];
  a[1,n+1]:=a[1,1];
  a[2,n+1]:=a[2,1];
  for i:=1 to m do
    read(l[i])
end;

procedure writedata;
 var i:int;
begin
  writeln('YES');
  for i:=1 to n do
    write(ans[i],' ');
  halt(0)
end;

procedure solve;
 var i,j,lf:int;
     f,ansb:bool;
begin
  for i:=1 to n do
    ans[i]:=-1;
  for i:=1 to m do
    used[i]:=false;
  ansb:=true;
  i:=1;
  while i<=n do begin
    lf:=abs(a[1,i]-a[1,i-1])+abs(a[2,i]-a[2,i-1])+abs(a[1,i]-a[1,i+1])+abs(a[2,i]-a[2,i+1]);
    f:=false;
    for j:=1 to m do
      if (not used[j])and(l[j]=lf)then begin
        used[j]:=true;
        ans[i]:=j;
        f:=true;
        break
      end;
    if not f then begin
      ansb:=false;
      break
    end;
    inc(i,2)
  end;
  if ansb then writedata;

  for i:=1 to n do
    ans[i]:=-1;
  for i:=1 to m do
    used[i]:=false;
  ansb:=true;
  i:=2;
  while i<=n do begin
    lf:=abs(a[1,i]-a[1,i-1])+abs(a[2,i]-a[2,i-1])+abs(a[1,i]-a[1,i+1])+abs(a[2,i]-a[2,i+1]);
    f:=false;
    for j:=1 to m do
      if (not used[j])and(l[j]=lf)then begin
        used[j]:=true;
        ans[i]:=j;
        f:=true;
        break
      end;
    if not f then begin
      ansb:=false;
      break
    end;
    inc(i,2)
  end;
  if ansb then writedata;

  writeln('NO')
end;

begin
  {$IFNDEF ONLINE_JUDGE}
  reset(input,'input.txt');
  rewrite(output,'output.txt');
  {$ENDIF}
  readdata;
  solve
end.