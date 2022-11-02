program code6;

{$APPTYPE CONSOLE}
{$minstacksize 16000000}
uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean;
var n,m,v:int;
    a:array[0..100100,1..2]of int;

procedure swap(var a,b:int);
 var c:int;
begin
 c:=a;
 a:=b;
 b:=c
end;

procedure writeno;
begin
 writeln(-1);
 halt(0)
end;

procedure readdata;
begin
 readln(n,m,v);
 if m<2 then writeno;
end;

procedure solve;
 var x,i,j,z:int;
begin
 if m<n-1 then writeno;

 for z:=2 to n-1 do begin
  x:=0;
  for i:=1 to n-1 do begin
   inc(x);
   a[x,1]:=i;
   a[x,2]:=i+1
  end;

  for i:=1 to z do
   for j:=i+1 to z do
    if x=m then break
     else
      if (i<>j)and(abs(i-j)<>1) then begin
                    inc(x);
                    a[x,1]:=i;
                    a[x,2]:=j
                   end;

  for i:=z to n do
   for j:=i+1 to n do
    if x=m then break
     else
      if(i<>j)and(abs(i-j)<>1)then begin
                    inc(x);
                    a[x,1]:=i;
                    a[x,2]:=j
                   end;
  if x=m then begin
   for i:=1 to m do begin
    if a[i,1]=v then write(z,' ')
     else if a[i,1]=z then write(v,' ')
      else write(a[i,1],' ');
    if a[i,2]=v then writeln(z)
     else if a[i,2]=z then writeln(v)
      else writeln(a[i,2]);
   end;
   halt(0);
  end;
 end;
 writeno;
end;

begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readdata;
 solve
end.