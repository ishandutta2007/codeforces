uses math;
var
  mat:array[0..10,0..10,0..10,0..10]of longint;
  a:array[1..10,1..10]of longint;
  n,m,kil,k:longint;
  ans:longint;
  zn1,zn2:longint;
  i,j,l,o:longint;
begin
  read(n,m,kil,k);
  for i:=1 to kil do
    begin
      read(zn1,zn2);
      inc(a[zn1,zn2]);
    end;

  for i:=1 to n do
    for j:=1 to m do
      for l:=i to n do
        for o:=j to m do
          mat[i,j,l,o]:=mat[i,j,l,o-1]+mat[i,j,l-1,o]-mat[i,j,l-1,o-1]+a[l,o];

  for i:=1 to n do
    for j:=1 to m do
      for l:=i to n do
        for o:=j to m do
          if mat[i,j,l,o]>=k then inc(ans);

  writeln(ans);
end.