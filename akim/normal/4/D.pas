type wh=record
         w,h,n,p,k:longint;
        end;
var a:array[0..5050]of wh;
    vr:wh;
    t:string;
    s:ansistring;
    n,i,f,max,maxi:longint;
begin
 readln(n,a[0].w,a[0].h);
 f:=1;
 for i:=1 to n do
 begin
  readln(a[f].w,a[f].h);a[f].n:=i;
  if (a[f].w>a[0].w)and(a[f].h>a[0].h) then inc(f);
 end;n:=f-1;
 for i:=1 to n-1 do
  for f:=i+1 to n do
   if a[i].w>a[f].w then begin vr:=a[i];a[i]:=a[f];a[f]:=vr;end else
   if (a[i].w=a[f].w)and(a[i].h<a[f].h) then begin vr:=a[i];a[i]:=a[f];a[f]:=vr;end;
 max:=0;maxi:=0;
 for i:=1 to n do
  begin
  for f:=i-1 downto 0 do
   if (a[i].w>a[f].w)and(a[i].h>a[f].h)and(a[i].k<=a[f].k) then begin a[i].p:=f;a[i].k:=a[f].k+1;if a[i].k>max then begin max:=a[i].k;maxi:=i;end;end;
  end;
 writeln(a[maxi].k);
 while maxi>0 do
 begin
  str(a[maxi].n,t);
  s:=t+' '+s;
  maxi:=a[maxi].p;
 end;
 writeln(s);
end.