program code4;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type int=integer;
var n,m:int;
    a:array[-1..110,-1..110]of char;

procedure readdata;
 var i,j:int;
     mem:char;
     f:boolean;
begin
 readln(n,m);
 f:=true;
 for i:=1 to n do begin
  for j:=1 to m do
   read(a[i,j]);
  readln
 end;
 for i:=1 to n do begin
  mem:=a[i,1];
  for j:=1 to m do
   if a[i,j]<>mem then f:=false
 end;
 for i:=2 to n do
  if a[i,1]=a[i-1,1]then f:=false;
 if f then writeln('YES')
  else writeln('NO')
end;

procedure solve;

begin

end;

procedure writedata;

begin

end;

begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readdata;
 solve;
 writedata
end.