var
 dpsu,dpmin:array[0..100000]of longint;
 a,t,st:array[1..1000000]of longint;
 ssc1,ssc2,mmin,l1,l,stn,i,j,n,m,k,o,p,sc,sc1,ch1,ch2:longint;
begin
 readln(n);
 for i:=1 to n do readln(t[i]);
 dpsu[1]:=20;
 dpmin[1]:=20;
 l1:=1;
 l:=1;
 for i:=2 to n do
 begin
  ssc1:=maxlongint;
  ssc2:=maxlongint;
  while (t[l1]+1440<=t[i])and(l1<>i) do inc(l1);
  while (t[l]+90<=t[i])and(l<>i) do inc(l);
  if(l1<>i)and(l1<>i-1)then
  begin
   ch1:=abs(dpsu[l1]-dpsu[i-1])+dpmin[l1];

   ssc1:=120-ch1;
  end;
  if(l<>i)and(l<>i-1)then
  begin
   ch1:=abs(dpsu[l]-dpsu[i-1])+dpmin[l];
   ssc2:=50-ch1;
  end;
  if (ssc1<=20)and(ssc1<=ssc2)then dpmin[i]:=ssc1 else
  if(ssc2<=20)and(ssc2<=ssc1)then dpmin[i]:=ssc2 else dpmin[i]:=20;
  dpsu[i]:=dpsu[i-1]+dpmin[i];
 end;
 for i:=1 to n do writeln(dpmin[i]);
end.