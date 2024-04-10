type
 varray=array[0..100000]of longint;
var
 a,nch:varray;
 ans:int64;
 min,dp,t,l1,r1,l,r,sch,snch,i,j,k,o,p,n:longint;
procedure swap(var a,b:longint);
var c:longint;
begin
 c:=a;
 a:=b;
 b:=c;
end;
procedure sort(l,r:longint; var a:varray);
var i,j,m:longint;
begin
 i:=l;
 j:=r;
 m:=a[l+random(r-l+1)];
 repeat
  while a[i]<m do inc(i);
  while a[j]>m do dec(j);
  if i>j then break;
  swap(a[i],a[j]);
  inc(i); dec(j);
 until i>j;
 if i<r then sort(i,r,a);
 if l<j then sort(l,j,a);
end;
begin
 randomize;
// assign(input,'input.txt'); reset(input);
// assign(output,'dop.txt'); rewrite(output);
 readln(n);
 min:=maxlongint;
 ans:=0;
 for i:=1 to n do
 begin
  read(a[i]);
  if a[i] mod 2=0 then begin if a[i]>0 then ans:=ans+a[i]; end
   else
  begin
   inc(snch);
   nch[snch]:=a[i];
  end;
 end;
 sort(1,snch,nch);
// for i:=1 to snch do writeln(nch[i]);
 if snch mod 2=0 then
 begin
  for i:=snch downto 2 do if nch[i]>0 then begin ans:=ans+nch[i];
                                           if nch[i]<min  then min:=nch[i];
                                           end;

  if ans mod 2=0 then
  begin

   for i:=snch downto 1 do if nch[i]<0 then
   begin
    if abs(nch[i])>min then begin dec(ans,min); break; end;
    ans:=ans+nch[i];
    break;
   end;
  end;
 end else
  if snch mod 2=1 then
  begin
   for i:=snch downto 1 do if nch[i]>0 then begin ans:=ans+nch[i];
                                           if nch[i]<min  then min:=nch[i];
                                           end;

    if ans mod 2=0 then
  begin

   for i:=snch downto 1 do if nch[i]<0 then
   begin
    if abs(nch[i])>min then begin dec(ans,min); break; end;
    ans:=ans+nch[i];
    break;
   end;
  end;
 end;
 writeln(ans);
end.