type mas=record a:longint;e:longint;vkl:boolean;end;
var a:array[1..100000]of mas;
    i,f,k,n,m:longint;
    log:boolean;
    c:char;
begin
 a[1].e:=1;
 readln(n,m);
 for i:=2 to n do
 begin
  if a[i].e=0 then
  begin
   f:=i;
   while f<=n do
   begin
    a[f].e:=i;
    inc(f,i);
   end;
  end;
  a[i].vkl:=false;
 end;
 for i:=1 to m do
 begin
  readln(c,k);
  if c='+' then 
  begin
   if a[k].vkl=true then writeln('Already on')else
   begin
    f:=k;log:=false;
    while (f>1) do
    begin
     if a[f].a<>0 then begin log:=true;break;end;
     if a[a[f].e].a<>0 then begin f:=a[f].e;log:=true;break;end;
     f:=f div a[f].e;
    end;
    if log then writeln('Conflict with ',a[f].a)
    else
    begin
     a[k].vkl:=true;
     f:=k;
     while (f>1) do
     begin
      a[f].a:=k;
      a[a[f].e].a:=k;
      f:=f div a[f].e;
     end;
     writeln('Success');
    end;
   end;
  end;
  if c='-' then 
  begin
   if a[k].vkl=false then writeln('Already off')else
   begin
    a[k].vkl:=false;
    while (k>1) do
    begin
     a[k].a:=0;
     a[a[k].e].a:=0;
     k:=k div a[k].e;
    end;
    writeln('Success');
   end;
  end;
 end;
end.