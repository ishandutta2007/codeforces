VAR
  a, b, x, y, ans, w: LONGINT;
BEGIN
  READLN(a,b);
  READLN(x,y);
  IF x>a
  THEN
    BEGIN
      w := a;
      a := x;
      x := w;
    END;
  IF b<y
  THEN
    BEGIN
      w := b;
      b := y;
      y := w;
    END;
  ans := a+b-x-y+2;
  ans := ans*2;
  IF (a=x) OR (b=y)
  THEN
    ans := ans+2;
  IF (a=x) AND (b=y)
  THEN
    ans := 8;
  WRITELN(ans);
END.