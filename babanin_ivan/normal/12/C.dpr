program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type int=integer;
     fruct=record
      s:string;
      k:int
     end;
var a:array[0..200]of int;
    b:array[0..200]of fruct;
    n,m,x:int;

procedure readdata;
 var i,j:int;
     s:string;
     f:boolean;
begin
 readln(n,m);
 for i:=1 to n do
  read(a[i]);
 readln;
 x:=0;
 for i:=1 to m do begin
  readln(s);
  f:=false;
  for j:=1 to x do
   if b[j].s=s then begin
    f:=true;
    inc(b[j].k)
   end;
  if not f then begin
   inc(x);
   b[x].s:=s;
   b[x].k:=1
  end
 end;
end;

procedure swapf(var a,b:fruct);
 var c:fruct;
begin
 c:=a;
 a:=b;
 b:=c
end;

procedure swap(var a,b:int);
 var c:int;
begin
 c:=a;
 a:=b;
 b:=c
end;

procedure solve;
 var f:boolean;
     i,j,min,max:int;
begin
 for i:=1 to n do
  for j:=1 to n do
   if a[i]<a[j] then swap(a[i],a[j]);
 for i:=1 to x do
  for j:=1 to x do
   if b[i].k<b[j].k then swapf(b[i],b[j]);
 min:=0;
 max:=0;
 j:=1;
 for i:=x downto 1 do begin
  inc(min,b[i].k*a[j]);
  inc(j)
 end;
 j:=n;
 for i:=x downto 1 do begin
  inc(max,b[i].k*a[j]);
  dec(j);
 end;
 writeln(min,' ',max)
end;

begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readdata;
 solve;
end.