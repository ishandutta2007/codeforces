program code4;

{$APPTYPE CONSOLE}
{$minstacksize 16000000}
uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     football=record
      n:string;
      s,g1,g2:int
     end;
var a:array[-10..100]of football;
    n:int;

procedure swapf(var a,b:football);
 var c:football;
begin
 c:=a;
 a:=b;
 b:=c
end;

procedure match;
 var s,s1,s2:string;
     num1,num2,name1,name2,i,j:int;
begin               
 readln(s);
 s1:='';
 i:=1;
 while s[i]<>'-' do begin
  s1:=s1+s[i];
  inc(i)
 end;
 inc(i);
 s2:='';
 while s[i]<>' ' do begin
  s2:=s2+s[i];
  inc(i)
 end;

 for j:=1 to n do begin
  if a[j].n=s1 then name1:=j;
  if a[j].n=s2 then name2:=j
 end;

 num1:=0;
 num2:=0;
 inc(i);
 while s[i]<>':' do begin
  num1:=num1*10+ord(s[i])-ord('0');
  inc(i)
 end;
 inc(i);
 while (i<=length(s))and(ord(s[i])<=ord('9'))and(ord(s[i])>=ord('0')) do begin
  num2:=num2*10+ord(s[i])-ord('0');
  inc(i)
 end;

 if num1<>num2 then begin
  if num1>num2 then inc(a[name1].s,3);
  if num1<num2 then inc(a[name2].s,3);
 end;
 if num1=num2 then begin
  inc(a[name1].s);
  inc(a[name2].s)
 end;
 inc(a[name1].g1,num1);
 inc(a[name1].g2,num2);
 inc(a[name2].g1,num2);
 inc(a[name2].g2,num1)
end;

procedure readdata;
 var i:int;
begin
 readln(n);
 for i:=1 to n do
  readln(a[i].n);
 for i:=1 to n*(n-1) div 2 do match
end;

function comp(i,j:int):boolean;
begin
 if i=j then begin
  comp:=false;
  exit
 end;
 if a[i].s<>a[j].s then begin
  if a[j].s>a[i].s then comp:=true
   else comp:=false;
  exit
 end;
 if (a[i].g1-a[i].g2)<>(a[j].g1-a[j].g2)then begin
  if (a[j].g1-a[j].g2)>(a[i].g1-a[i].g2) then comp:=true
   else comp:=false;
  exit
 end;
 if a[i].g1<a[j].g1 then comp:=true
  else comp:=false
end;

procedure qsort(l,r:int);
 var i,j,x:int;
begin
 i:=l;
 j:=r;
 x:=(l+r)div 2;;
 while i<=j do begin
  while comp(i,x) do inc(i);
  while comp(x,j) do dec(j);
  if i<=j then begin
   swapf(a[i],a[j]);
   inc(i);
   dec(j)
  end;
 end;
 if i<r then qsort(i,r);
 if l<j then qsort(l,j)
end;

procedure qsortx(l,r:int);
 var i,j,x:int;
begin
 i:=l;
 j:=r;
 x:=(l+r)div 2;
 while i<=j do begin
  while a[i].n<a[x].n do inc(i);
  while a[x].n<a[j].n do dec(j);
  if i<=j then begin
   swapf(a[i],a[j]);
   inc(i);
   dec(j)
  end;
 end;
 if i<r then qsortx(i,r);
 if l<j then qsortx(l,j)
end;

procedure solve;
 var i,j:int;
begin
 for i:=1 to n do
  for j:=1 to n-1 do
   if comp(j+1,j) then swapf(a[j],a[j+1]);

 for i:=(n div 2)+1 to n do
  for j:=(n div 2)+1 to n-1 do
   if a[j].n>a[j+1].n then swapf(a[j],a[j+1]);
 for i:=(n div 2)+1 to n do
  writeln(a[i].n)
end;

begin
 //{$IFNDEF ONLINE_JUDGE}
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 //{$ENDIF}
 readdata;
 solve
end.