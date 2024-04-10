program code8;

{$APPTYPE CONSOLE}
{$R+,Q+}
uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean;
const hash=997;
var a:array[-1..110,-1..110]of bool;
    match,d:array[-1..110]of int;
    used:array[-1..110]of bool;
    n:int;

procedure swap(var a,b:int);
 var c:int;
begin
  c:=a;
  a:=b;
  b:=c
end;

procedure readdata;
 var i,x,j:int;
begin
  readln(n);
  for i:=1 to n do begin
    read(x);
    match[x]:=i
  end;
  readln;
  for i:=1 to n do
    read(d[i]);

  for i:=1 to n do
    for j:=1 to n do
      a[i,j]:=false;

  for i:=1 to n do
    for j:=1 to n do
      if abs(i-j)=d[i] then begin
        a[i,j]:=true;
        a[j,i]:=true
      end
end;

procedure dfs(v:int);
 var i:int;
begin
  used[v]:=true;
  for i:=1 to n do
    if a[v,i] and (not used[i])then
      dfs(i)
end;

procedure solve;
 var i,j:int;
begin
  for i:=1 to n do begin
    for j:=1 to n do
      used[j]:=false;
    dfs(i);
    if not used[match[i]] then begin
      writeln('NO');
      halt(0)
    end
  end;
  writeln('YES')
end;

begin
  {$IFNDEF ONLINE_JUDGE}
  reset(input,'input.txt');
  rewrite(output,'output.txt');
  {$ENDIF}
  readdata;
  solve
end.