program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type int=integer;
var a:array[1..3,1..3]of char;

procedure readdata;
 var i,j:int;
begin
 for i:=1 to 3 do begin
  for j:=1 to 3 do
   read(a[i,j]);
  readln
 end
end;

procedure solve;
 var f:boolean;

begin
 f:=true;
 if a[1,1]<>a[3,3]then f:=false;
 if a[1,3]<>a[3,1]then f:=false;
 if a[2,1]<>a[2,3]then f:=false;
 if a[1,2]<>a[3,2]then f:=false;
 if f then writeln('YES')
  else writeln('NO')
end;

begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readdata;
 solve;
end.