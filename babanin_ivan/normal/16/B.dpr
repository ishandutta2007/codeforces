program code4;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type int=integer;
var n,m:int;
    ans:int64;
    a:array[1..100]of int;
    b:array[1..100]of int;

procedure readdata;
 var i:int;
begin
 readln(n,m);
 for i:=1 to m do begin
  read(a[i]);
  readln(b[i])
 end
end;

procedure swap(var a,b:int);
 var c:int;
begin
 c:=a;
 a:=b;
 b:=c
end;

procedure solve;
 var i,j:int;
begin
 for i:=1 to m do
  for j:=1 to m-1 do
   if b[j]>b[j+1] then begin
    swap(b[j+1],b[j]);
    swap(a[j+1],a[j])
   end;
 ans:=0;
 for i:=m downto 1 do
  if n>a[i] then begin
   n:=n-a[i];
   ans:=ans+a[i]*b[i]
  end
  else begin
        ans:=ans+n*b[i];
        exit
       end
end;

procedure writedata;
begin
 writeln(ans)
end;

begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readdata;
 solve;
 writedata
end.