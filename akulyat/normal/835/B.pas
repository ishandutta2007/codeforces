Program Maska;
type massiv=array[1..1000000]of longint;
var od,ord0,n,ind,sum,k:int64;
    i:longint;
    s:string;
    mas:massiv;

procedure swap(var c,d:longint );
begin
if c=d then
       else
         begin
           c:=c+d;
           d:=c-d;
           c:=c-d;
         end;  
end;

Procedure q_sort(var e:massiv; a,b:longint);
var i,j,k,t,q:longint;
begin

if a>=b then
else
  begin
    t:=random(b-a+1)+a;
    q:=e[t];
    swap(e[a], e[t]);
    i:=a; j:=a+1; k:=b;
    while j<=k do
      if e[j]=q then inc (j)
           else
             if e[j]<q then
                         begin
                           swap(e[i], e[j]);
                           inc(i);
                           inc(j);
                         end
                       else  
                         begin
                           swap(e[j], e[k]);
                           dec(k);
                         end;
   
   q_sort(e, a, i-1);
   
   q_sort(e, k+1, b);
  end;
end;  


begin
readln(k);
read(s);
ord0:=ord('0');
for i:=1 to length(s) do
  begin
  mas[i]:=ord(s[i])-ord0;
  sum:=sum+mas[i];
  end;
n:=length(s);
od:=1;
q_sort(mas, od, n);
ind:=0;
while sum<k do
  begin
  inc(ind);
  sum:=sum-mas[ind]+9;
  end;
write(ind);

end.