var
 a,b,c,st,s:array[1..600000]of longint;
 cs,i,j,k,l,ch1,ch2,max,n,sc:longint;
procedure swap(var a,b:longint);
var c:longint;
begin
 c:=a;
 a:=b;
 b:=c;
end;
function min(a,b,c:longint):longint;
begin
 if(a<=b)and(a<=c)then min:=a else
  if (b<=a)and(b<=c)then min:=b else min:=c;
end;
function comp(a,b,c,am,bm,cm:longint):boolean;
begin
 comp:=(a<am)or((a=am)and(b<bm))or((a=am)and(b=bm)and(c<cm))
end;
procedure sort(l,r:longint);
var ch1,am,bm,cm,i,j:longint;
begin
 i:=l;
 j:=r;
 ch1:=l+random(r-l+1);
 am:=a[ch1];
 bm:=b[ch1];
 cm:=c[ch1];
 repeat
  while comp(a[i],b[i],c[i],am,bm,cm) do inc(i);
  while comp(am,bm,cm,a[j],b[j],c[j]) do dec(j);
  if i>j then break;
  swap(a[i],a[j]);
  swap(b[i],b[j]);
  swap(c[i],c[j]);
  swap(s[i],s[j]);
  inc(i); dec(j);
 until i>j;
 if j>l then sort(l,j);
 if i<r then sort(i,r);
end;
begin
 readln(n);
 for i:=1 to n do
 begin
  readln(a[i],b[i],c[i]);
  s[i]:=i;
  s[n+i]:=i;
  s[n*2+i]:=i;
  s[n*3+i]:=i;
  s[n*4+i]:=i;
  s[n*5+i]:=i;
  a[n*1+i]:=a[i]; b[n*1+i]:=c[i]; c[n*1+i]:=b[i];
  a[n*2+i]:=b[i]; b[n*2+i]:=a[i]; c[n*2+i]:=c[i];
  a[n*3+i]:=b[i]; b[n*3+i]:=c[i]; c[n*3+i]:=a[i];
  a[n*4+i]:=c[i]; b[n*4+i]:=a[i]; c[n*4+i]:=b[i];
  a[n*5+i]:=c[i]; b[n*5+i]:=b[i]; c[n*5+i]:=a[i];
 end;
 for i:=1 to n do
 begin
  if min(a[i],b[i],c[i])>max then
  begin
   max:=min(a[i],b[i],c[i]);
   k:=1;
   st[1]:=s[i];
  end;
 end;
 n:=n*6;
 sort(1,n);
 for i:=1 to n-1 do if(a[i]=a[i+1])and(b[i]=b[i+1])and(s[i]<>s[i+1])then
 begin
  cs:=c[i]+c[i+1];
  if min(a[i],b[i],cs)>max then
  begin
   max:=min(a[i],b[i],cs);
   k:=2;
   st[1]:=s[i];
   st[2]:=s[i+1];
  end;
 end;
 writeln(k);
 for i:=1 to k do write(st[i],' ');
end.