var a:array [1..100] of integer;
    p,n,i,j,max,min,mx,mn:integer;
begin
 read (n);
 for i:=1 to n do
  read (a[i]);
 max:=a[1];
 mx:=1;
 for i:=2 to n do
  if a[i]>max then begin max:=a[i]; mx:=i; end;
 while mx<>1 do
  begin
   p:=a[mx];
   a[mx]:=a[mx-1];
   a[mx-1]:=p;
   dec (mx);
   inc (j);
  end;

 min:=a[2];
 mn:=2;
 for i:=3 to n do
  if a[i]<=min then begin min:=a[i]; mn:=i; end;
 while mn<>n do
  begin
   p:=a[mn];
   a[mn]:=a[mn-1];
   a[mn-1]:=p;
   inc (mn);
   inc (j);
  end;

 write (j);
end.